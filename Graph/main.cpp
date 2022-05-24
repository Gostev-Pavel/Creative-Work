#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <string>
#include <climits>
using namespace sf;

//Глобальные переменные
const int win_w = 1280;
const int win_h = 720;
const float pi = acosf(-1);
const int R_range = 260;
const Vector2f R_center(win_w / 2.3, win_h / 2.3);
const float R_vert = 20.f;
const int dots = 100;
Font typeface;

//Классы
class Matrix {
public:
	std::vector<std::vector<int>> adMat;
private:
	static bool pathFinder(std::vector <std::vector<int>> mat) {
		bool f = false;

		for (int i = 0; i < mat.size() && !f; i++)
			for (int j = 0; j < mat.size() && !f; j++)
				if (mat[i][j] != INT32_MAX)
					f = true;
		return f;
	}
public:
	Matrix(){}

	Matrix(const Matrix& adMatrix) {
		this->adMat = std::vector<std::vector<int>>(adMatrix.get_tops());
		for (unsigned int i = 0; i < adMatrix.get_tops(); ++i)
			copy(adMatrix.adMat[i].begin(), adMatrix.adMat[i].end(), back_inserter(adMat[i]));
	}

	Matrix(std::vector<std::vector<int>>& mat) {
		this->adMat = std::vector<std::vector<int>>(mat.size());

		for (int i = 0; i < get_tops(); i++)
			copy(mat[i].begin(), mat[i].end(), back_inserter(this->adMat[i]));

		for (int i = 0; i < get_tops(); i++)
			this->adMat[i][i] = INT32_MAX;
	}

	int get_tops() const { return adMat.size(); }

	std::vector<std::pair<int, int>> pathways() const {
		std::vector<std::pair<int, int>> paths;
		std::vector<std::vector<int>> backup(get_tops());

		for (int i = 0; i < get_tops(); i++)
			copy(adMat[i].begin(), adMat[i].end(), back_inserter(backup[i]));

		while (pathFinder(backup)) {
			//минимумы строк
			std::vector<int> minLine(get_tops());
			for (int i = 0; i < get_tops(); i++)
				minLine[i] = *min_element(backup[i].begin(), backup[i].end());
			//редукция строк
			for (int i = 0; i < get_tops(); i++)
				for_each(backup[i].begin(), backup[i].end(), [&i, &minLine](int& digit)->void {if (digit != INT32_MAX) digit -= minLine[i]; });
			//минимумы столбцов
			std::vector<int> minCol(get_tops());
			for (int j = 0; j < get_tops(); j++) {
				int lowest = INT32_MAX;
				for (int i = 0; i < get_tops(); i++)

					if (backup[i][j] < lowest)
						lowest = backup[i][j];

				minCol[j] = lowest;
			}
			//редукция столбцов
			for (int j = 0; j < get_tops(); j++)
				for (int i = 0; i < get_tops(); i++)

					if (backup[i][j] != INT32_MAX)
						backup[i][j] -= minCol[j];
			//оценка нулей
			for (int i = 0; i < get_tops(); i++) {
				for (int j = 0; j < get_tops(); j++)

					if (backup[i][j] <= 0) {
						int minl = INT32_MAX;
						int minc = INT32_MAX;
						for (int cnt = 0; cnt < get_tops(); cnt++) {

							if (backup[i][cnt] < 0)
								minl = 0;

							else if (backup[i][cnt] < minl && cnt != j)
								minl = backup[i][cnt];

							if (backup[cnt][j] < 0)
								minc = 0;

							else if (backup[cnt][j] < minc && cnt != i)
								minc = backup[cnt][j];
						}
						backup[i][j] = -1 * (minl + minc);
					}
			}
			//поиск наибольшей оценки
			int maxScore = INT32_MAX, maxScore_l = INT32_MAX, maxScore_c = INT32_MAX;
			for (int l = 0; l < get_tops(); l++)
				for (int c = 0; c < get_tops(); c++)

					if (maxScore > backup[l][c]) {
						maxScore = backup[l][c];
						maxScore_l = l;
						maxScore_c = c;
					}
			paths.push_back(std::pair<int, int>{maxScore_l, maxScore_c});
			//отметка найденного пути и очищение матрицы от оценок
			for (int i = 0; i < get_tops(); i++)
				for (int j = 0; j < get_tops(); j++) {

					if (i == maxScore_l)
						backup[i][j] = INT32_MAX;

					if (j == maxScore_c)
						backup[i][j] = INT32_MAX;

					if (backup[i][j] < 0)
						backup[i][j] = 0;
				}
			backup[maxScore_c][maxScore_l] = INT32_MAX;
		}
		return paths;
	}

	std::vector<int> getPath(int start)const {
		if (start >= 0 && start < adMat.size()) {
			std::vector<std::pair<int, int>> ways = pathways();
			std::vector<int> path(adMat.size() + 1);
			bool f;
			int curP = start;

			for (int i = 0; i < path.size(); i++) {
				f = false;
				for (int j = 0; j < ways.size() && !f; j++)

					if (ways[j].first == curP) {
						path[i] = curP;
						curP = ways[j].second;
						f = true;
					}
				if (!f)
					throw std::invalid_argument("Решение для данной точки не найдено!");
			}
			return path;
		}else throw std::invalid_argument("Указанной точки не существует!");
	}

	int getSum(std::vector<std::pair<int, int>>& v) const {
		int summa = 0;

		for (int i = 0; i < v.size(); i++)
			summa += adMat[v[i].first][v[i].second];

		return summa;
	}
};

class Node : public Drawable {
	Text note;
	CircleShape circle;
public:
	Node(){}

	Node(const sf::String& text, const int& size) {
		this->note = Text(L"" + text, typeface, size);
		this->note.setFillColor(Color::Black);

		circle = CircleShape(R_vert, dots);

		circle.setOutlineThickness(3.f);
		circle.setOutlineColor(Color::Magenta);
		circle.setFillColor(Color::Cyan);
	}

	void setPos(float x, float y) {
		circle.setPosition(x, y);
		note.setPosition(x + (circle.getLocalBounds().width / 2.3) - (note.getLocalBounds().width / 2.3), y + (circle.getLocalBounds().height / 2.3) - (note.getLocalBounds().height));
	}

	void draw(RenderTarget& obj, RenderStates statuses)const {
		obj.draw(circle, statuses);
		obj.draw(note, statuses);
	}

	FloatRect getGlobalBounds() { return circle.getGlobalBounds(); }
	FloatRect getLocalBounds() { return circle.getLocalBounds(); }

	Vector2f getCenter() {
		return Vector2f(circle.getPosition().x + (circle.getLocalBounds().width / 2), circle.getPosition().y + (circle.getLocalBounds().height / 2));
	}

	Vector2f getPosition() {
		return Vector2f(circle.getPosition().x, circle.getPosition().y);
	}

	static void getRange(std::vector<Node>& tops) {
		for (int i = 0; i < tops.size(); i++)
			tops[i].setPos(R_center.x + R_range * cosf(2 * pi * i / tops.size()), R_center.y + R_range * sinf(2 * pi * i / tops.size()));
	}
};

class Edge : public Drawable {
	Vertex line[2];
	Text start_text;
	Text end_text;
	int start_len = INT32_MAX;
	int end_len = INT32_MAX;

	static float getLen(const Vector2f& v) { return sqrtf(pow(v.x, 2) + pow(v.y, 2)); }
	static Vector2f getOneVec(const Vector2f& v) { return Vector2f(v.x / getLen(v), v.y / getLen(v)); }
	static Vector2f getVec(const Vector2f& start, const Vector2f& end) { return Vector2f(end.x - start.x, end.y - end.y); }
public:
	Vector2f getCenter(const Vector2f& start, const Vector2f& end) { return Vector2f((start.x + end.x) / 2, (start.y + end.y) / 2); }
	Vector2f getStart() { return line[0].position; }
	Vector2f getEnd() { return line[1].position; }
private:
	Vector2f getStartCenter() { return getCenter(getCenter(line[0].position, line[1].position), line[0].position); }
	Vector2f getEndCenter() { return getCenter(getCenter(line[0].position, line[1].position), line[1].position); }
public:
	Edge(const int& startLen, const int& endLen, const int& size) {
		this->start_len = startLen;
		this->end_len = endLen;

		start_text.setFont(typeface);
		end_text.setFont(typeface);

		start_text.setFillColor(Color::Yellow);
		end_text.setFillColor(Color::Yellow);

		start_text.setCharacterSize(size);
		end_text.setCharacterSize(size);

		start_text.setString(std::to_string(startLen));
		end_text.setString(std::to_string(endLen));

		line[0].color = Color::Magenta;
		line[1].color = Color::Magenta;
	}

	void setPos(const Vector2f& start, const Vector2f& end) {
		line[0].position = start;
		line[1].position = end;

		if (start_len != INT32_MAX)
			start_text.setPosition(getStartCenter());

		if (end_len != INT32_MAX)
			end_text.setPosition(getEndCenter());
	}

	void draw(RenderTarget& obj, RenderStates statuses) const {
		obj.draw(line, 2, Lines, statuses);

		if (start_len != INT32_MAX)
			obj.draw(start_text, statuses);

		if (end_len != INT32_MAX)
			obj.draw(end_text, statuses);
	}

	void paintTextEnd() {end_text.setFillColor(Color::White);}
	void paintTextStart() { start_text.setFillColor(Color::White); }
};

class Graph {
public:
	Matrix adMatrix;
	std::vector<Edge> ribs;
	std::vector<Node> nodes;

	void ConnectNE() {
		int cnt = 0;

		for (int i = 0; i < adMatrix.get_tops(); i++)
			for (int j = i + 1; j < adMatrix.get_tops(); j++)

				if (adMatrix.adMat[i][j] != INT32_MAX || adMatrix.adMat[j][i] != INT32_MAX) {
					ribs[cnt].setPos(nodes[i].getCenter(), nodes[j].getCenter());
					cnt++;
				}
	}

	Graph(std::vector<std::vector<int>>& Mat, const std::vector<std::wstring>& titles, const Font& typeFace, const int& size = 14,
		const Vector2f& Scatter_Center = Vector2f(400.f, 260.f), const int& Scatter_R = 300) {
		this->adMatrix = Matrix(Mat);
		nodes = std::vector<Node>(adMatrix.get_tops());

		for (int i = 0; i < adMatrix.get_tops(); i++)
			nodes[i] = Node(titles[i], size);

		Node::getRange(nodes);

		for (int i = 0; i < adMatrix.get_tops(); i++)
			for (int j = i + 1; j < adMatrix.get_tops(); j++) {
				if (adMatrix.adMat[i][j] != INT32_MAX && adMatrix.adMat[j][i] != INT32_MAX) {
					ribs.push_back(Edge(adMatrix.adMat[i][j], adMatrix.adMat[j][i], size));
					ribs.back().setPos(nodes[i].getCenter(), nodes[j].getCenter());

				}else if (adMatrix.adMat[i][j] == INT32_MAX && adMatrix.adMat[j][i] != INT32_MAX) {
					ribs.push_back(Edge(INT32_MAX, adMatrix.adMat[j][i], size));
					ribs.back().setPos(nodes[i].getCenter(), nodes[j].getCenter());

				}else if (adMatrix.adMat[i][j] != INT32_MAX && adMatrix.adMat[j][i] == INT32_MAX) {
					ribs.push_back(Edge(adMatrix.adMat[i][j], INT32_MAX, size));
					ribs.back().setPos(nodes[i].getCenter(), nodes[j].getCenter());
				}
			}
	}

	void paintRightWay() {
		std::vector<std::pair<int, int>> units = adMatrix.pathways();

		for (int i = 0; i < units.size(); i++)
			for (int j = 0; j < ribs.size(); j++) {
				if (ribs[j].getStart() == nodes[units[i].first].getCenter() && ribs[j].getEnd() == nodes[units[i].second].getCenter())
					ribs[j].paintTextStart();

				if (ribs[j].getStart() == nodes[units[i].second].getCenter() && ribs[j].getEnd() == nodes[units[i].first].getCenter())
					ribs[j].paintTextEnd();
			}
	}

	void UploadData(std::vector<std::vector<int>>& mtrx, const std::vector<std::wstring>& titles, const Font& face, const int& size, const Vector2f& Rcenter,
		const int& Rrange) {
		ribs.erase(ribs.begin(), ribs.end());

		this->adMatrix = Matrix(mtrx);
		nodes = std::vector<Node>(adMatrix.get_tops());

		for (int i = 0; i < adMatrix.get_tops(); i++)
			nodes[i] = Node(titles[i], size);

		Node::getRange(nodes);

		for (int i = 0; i < adMatrix.get_tops(); i++)
			for (int j = i + 1; j < adMatrix.get_tops(); j++) {

				if (adMatrix.adMat[i][j] != INT32_MAX && adMatrix.adMat[j][i] != INT32_MAX) {
					ribs.push_back(Edge(adMatrix.adMat[i][j], adMatrix.adMat[j][i], size));
					ribs.back().setPos(nodes[i].getCenter(), nodes[j].getCenter());
				}else if (adMatrix.adMat[i][j] == INT32_MAX && adMatrix.adMat[j][i] != INT32_MAX) {
					ribs.push_back(Edge(INT32_MAX, adMatrix.adMat[j][i], size));
					ribs.back().setPos(nodes[i].getCenter(), nodes[j].getCenter());
				}else if (adMatrix.adMat[i][j] != INT32_MAX && adMatrix.adMat[j][i] == INT32_MAX) {
					ribs.push_back(Edge(adMatrix.adMat[i][j], INT32_MAX, size));
					ribs.back().setPos(nodes[i].getCenter(), nodes[j].getCenter());
				}
			}
	}
};

class Button: public Drawable{
	RectangleShape shape;
	Text txt;
public:
	Button(const std::wstring& text, const Font& face, const float& w, const float& h) {
		this->txt.setString(text);
		this->txt.setFont(face);
		this->txt.setCharacterSize(14);
		this->txt.setFillColor(Color::Black);

		this->shape.setSize(Vector2f(w, h));
		this->shape.setFillColor(Color::Magenta);
		this->shape.setOutlineThickness(2.f);
		this->shape.setOutlineColor(Color::Cyan);
	}

	void ButtonEvent(const Vector2i& mousePos, Clock& time, const Event& evnt, std::function<void()> act) {
		if (shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			float period = time.getElapsedTime().asMilliseconds();
			bool f_Active = true;

			if (period < 6.f)
				f_Active = false;
			else
				time.restart();

			shape.setOutlineThickness(3.f);

			if (evnt.type == Event::MouseButtonPressed) {
				if (evnt.key.code == Mouse::Left && f_Active)
					shape.setFillColor(Color::Yellow);
			}else if (evnt.type == Event::MouseButtonReleased && f_Active) {
				if (evnt.key.code == Mouse::Left) {
					shape.setFillColor(Color::Magenta);
					act();
				}
			}
		}else {
			shape.setOutlineThickness(2.f);
			shape.setFillColor(Color::Magenta);
		}
	}

	void PositionSet(const float& x, const float& y) {
		shape.setPosition(x - shape.getLocalBounds().width / 2, y - shape.getLocalBounds().height / 2);
		txt.setPosition(x - txt.getLocalBounds().width / 2, y - txt.getLocalBounds().height / 2);
	}

	void draw(RenderTarget& obj, RenderStates statuses) const {
		obj.draw(shape, statuses);
		obj.draw(txt, statuses);
	}
};

//Глобальные функции
int getInput(const std::string& msg, int min = INT32_MIN, int max = INT32_MAX) {
	int num = 0;
	while (true) {
		std::cout << msg;

		std::string input;
		std::getline(std::cin, input);

		if (input.length() == 0)
			continue;

		const int cnt = count_if(input.begin(), input.end(), [](char symbol) {return isdigit(symbol); });

		if (static_cast<size_t>(cnt) == input.length()) {
			const int tmp = std::stoll(input);
			
			if (tmp <= std::numeric_limits<int>::max()) {
				num = static_cast<int>(tmp);

				if (num >= min && num <= max)
					break;
			}
		}
	}
	return num;
}

std::vector<std::vector<int>> enterMatrix(std::vector<std::wstring>& titles) {
	bool f_Input = false;
	int cnt = getInput("Введите количество вершин: ", 3, 8);
	std::vector<std::vector<int>> mtrx(cnt);

	for (int i = 0; i < cnt; i++)
		mtrx[i] = std::vector<int>(cnt);

	titles.erase(titles.begin(), titles.end());
	titles.resize(cnt);

	for (int i = 0; i < cnt; i++)
		titles[i] = std::to_wstring(i + 1);

	int tmp = 0;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (i != j) {
				tmp = getInput("Введите длину дороги из пункта " + std::to_string(i + 1) + " в пункт " + std::to_string(j + 1) + ": ");

				if (tmp <= 0)
					mtrx[i][j] = INT32_MAX;
				else mtrx[i][j] = tmp;

			}else mtrx[i][j] = INT32_MAX;
		}
		titles.push_back(std::to_wstring(i + 1));
	}

	return mtrx;
}

void removeTop(std::vector<std::vector<int>>& mtrx, std::vector<std::wstring>& titles) {
	bool f = false;
	int rTop;

	do {
		rTop = getInput("Введите желаемую для удаления вершину: ", 1);

		for (int i = 0; i < titles.size() && !f; i++)
			if (std::to_wstring(rTop) == titles[i]) {
				f = true;
				rTop = i;
			}

		if (!f) std::cout << "Введённая вершина отсутствует!" << std::endl;

	} while (!f);

	std::vector<std::vector<int>> copy(mtrx.size() - 1);

	for (int i = 0; i < copy.size(); i++)
		copy[i] = std::vector<int>(copy.size());

	for (int i = 0; i < mtrx.size(); i++)
		for (int j = 0; j < mtrx.size(); j++) {
			if (i < rTop && j < rTop)
				copy[i][j] = mtrx[i][j];
			else if (i < rTop && j > rTop)
				copy[i][j - 1] = mtrx[i][j];

			if (i > rTop && j < rTop)
				copy[i - 1][j] = mtrx[i][j];
			else if (i > rTop && j > rTop)
				copy[i - 1][j - 1] = mtrx[i][j];
		}

	mtrx = copy;
	int i = 0;

	for (auto iter = titles.begin(); i <= rTop; ++i, ++iter)
		if (i == rTop) {
			titles.erase(iter);
			break;
		}
}

void addTop(std::vector<std::vector<int>>& mtrx, std::vector<std::wstring>& titles) {
	for (int i = 0; i < mtrx.size(); i++)
		mtrx[i].resize(mtrx[i].size() + 1);

	mtrx.resize(mtrx.size() + 1);
	mtrx.back() = std::vector<int>(mtrx.size());

	titles.push_back(std::to_wstring(std::stoi(titles.back()) + 1));

	int tmp;
	for (int i = 0; i < mtrx.size() - 1; i++) {
		std::cout << "Введите длину дороги из пункта ";
		std::wcout << titles[i];
		std::cout << " в пункт ";
		std::wcout << titles.back();
		std::cout << ": ";

		tmp = getInput("", 0);
		if (tmp <= 0)
			mtrx[i].back() = INT32_MAX;
		else
			mtrx[i].back() = tmp;
	}

	for (int i = 0; i < mtrx.size() - 1; i++) {
		std::cout << "Введите длину дороги из пункта ";
		std::wcout << titles.back();
		std::cout << " в пункт ";
		std::wcout << titles[i];
		std::cout << ": ";

		tmp = getInput("", 0);
		if (tmp <= 0)
			mtrx.back()[i] = INT32_MAX;
		else
			mtrx.back()[i] = tmp;
	}

	mtrx.back().back() = INT32_MAX;
}

void showMatrix(std::vector<std::vector<int>>& mtrx, std::vector<std::wstring>& titles) {
	std::cout << "Исходная матрица смежности:";
	std::cout << std::endl;
	std::cout << "\t";

	for (int i = 0; i < mtrx.size(); i++)
		std::wcout << titles[i] << '\t';
	std::cout << std::endl;

	for (int i = 0; i < mtrx.size(); i++) {
		std::wcout << titles[i] << "\t";
		for (int j = 0; j < mtrx.size(); j++) {

			if (mtrx[i][j] == INT32_MAX)
				std::cout << 'M' << "\t";
			else std::cout << mtrx[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void showInfo(Graph& g, std::vector<std::wstring>& titles) {
	std::vector<std::pair<int, int>> ways = g.adMatrix.pathways();
	std::cout << "Отрезки оптимального пути:\n";

	for (int i = 0; i < ways.size(); i++)
		std::wcout << titles[ways[i].first] << L"->" << titles[ways[i].second] << std::endl;

	std::cout << "Длина оптимального пути: " << g.adMatrix.getSum(ways);
	std::cout << "\nОптимальный путь из пункта ";
	std::wcout << titles[0];
	std::cout << ':';

	std::vector<int> way = g.adMatrix.getPath(0);

	for (int i = 0; i < way.size(); i++) {
		if (i != way.size() - 1)
			std::wcout << titles[way[i]] << "->";
		else
			std::wcout << titles[way[i]] << std::endl;
	}
}

//Главная функция
int main() {
	setlocale(LC_ALL, "ru");

	ContextSettings settings;
	settings.antialiasingLevel = 9;
	typeface.loadFromFile("tahoma.ttf");
	RenderWindow window(VideoMode(win_w, win_h), "Graph", sf::Style::Close | sf::Style::Titlebar, settings);

	std::vector<std::wstring> names = { L"1", L"2", L"3", L"4", L"5", L"6"};
	std::vector<std::vector<int>> mtrx = {
		std::vector<int>{INT32_MAX, 5, 17, 23, 2, 10, 16},
		std::vector<int>{15, INT32_MAX, 9, 10, 19, 3, 31},
		std::vector<int>{24, 9, INT32_MAX, 22, 13, 46, 51},
		std::vector<int>{37, 4, 13, INT32_MAX, 26, 41, 20},
		std::vector<int>{6, 14, 15, 27, INT32_MAX, 33, 42},
		std::vector<int>{5, 4, 7, 31, 10, INT32_MAX, 8} };
	Graph gr(mtrx, names, typeface, 14);
	Button enter(L"Ввести матрицу", typeface, 150.f, 30.f);
	enter.PositionSet(90.f, 650.f);
	Button add(L"Добавить вершину", typeface, 150.f, 30.f);
	add.PositionSet(270.f, 650.f);
	Button del(L"Удалить вершину", typeface, 150.f, 30.f);
	del.PositionSet(450.f, 650.f);
	Clock timer;

	showMatrix(mtrx, names);
	showInfo(gr, names);

	gr.paintRightWay();

	while (window.isOpen()) {
		Vector2i cursor = Mouse::getPosition(window);
		Event evnt;

		while (window.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) window.close();

			enter.ButtonEvent(cursor, timer, evnt, [&gr, &names]()->void {
				system("cls");
				std::vector<std::vector<int>> mat = enterMatrix(names);
				showMatrix(mat, names);
				gr.UploadData(mat, names, typeface, 14, Vector2f(260.f, 260.f), 200);
				gr.paintRightWay();
				showInfo(gr, names); 
			});

			add.ButtonEvent(cursor, timer, evnt, [&gr, &names]()->void {
				if (gr.adMatrix.adMat.size() < 9) {
					system("cls");
					showMatrix(gr.adMatrix.adMat, names);
					addTop(gr.adMatrix.adMat, names);
					showMatrix(gr.adMatrix.adMat, names);
					gr.UploadData(gr.adMatrix.adMat, names, typeface, 14, Vector2f(260.f, 260.f), 200);
					gr.paintRightWay();
					showInfo(gr, names);
				}else std::cout << "Достигнут максимум вершин, добавление невозможно!" << std::endl;
				});

			del.ButtonEvent(cursor, timer, evnt, [&gr, &names]()->void {
				if (gr.adMatrix.adMat.size() > 3) {
					try {
						system("cls");
						showMatrix(gr.adMatrix.adMat, names);
						removeTop(gr.adMatrix.adMat, names);
						showMatrix(gr.adMatrix.adMat, names);
						gr.UploadData(gr.adMatrix.adMat, names, typeface, 14, Vector2f(260.f, 260.f), 200);
						gr.paintRightWay();
						showInfo(gr, names);
					}
					catch (std::exception& exc) {
						std::cout << exc.what() << std::endl;
					}
				}else std::cout << "Удаление невозможно!" << std::endl;
				});
		}

		window.clear(Color::Black);

		gr.ConnectNE();

		for (int i = 0; i < gr.ribs.size(); i++)
			window.draw(gr.ribs[i]);
		for (int i = 0; i < gr.nodes.size(); i++)
			window.draw(gr.nodes[i]);

		window.draw(enter);
		window.draw(del);
		window.draw(add);
		window.display();
	}
	return 0;
}
