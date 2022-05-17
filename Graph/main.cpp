#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <string>
#include <climits>
using namespace sf;

const int win_w = 800;
const int win_h = 600;
const float pi = acosf(-1);
const int R_range = 260;
const Vector2f R_center(win_w / 2.3, win_h / 2.3);
const float R_vert = 20.f;
const int dots = 100;
Font typeface;

class Matrix {
public:
	std::vector<std::vector<int>> adMat;
private:
	static bool pathFinder(std::vector <std::vector<int>> mat) {
		bool f = false;

		for (int i = 0; i < mat.size(); i++)
			for (int j = 0; j < mat.size(); j++)
				if (mat[i][j] != INT32_MAX)
					f = true;
		return f;
	}
public:
	Matrix(std::vector<std::vector<int>>& mat) {
		this->adMat = std::vector<std::vector<int>>(mat.size());

		for (int i = 0; i < get_tops(); i++)
			copy(mat[i].begin(), mat[i].end(), back_inserter(this->adMat[i]));

		for (int i = 0; i < get_tops(); i++)
			this->adMat[i][i] = INT32_MAX;
	}

	Matrix(int tops) {
		adMat = std::vector<std::vector<int>>(tops);

		for (int i = 0; i < tops; i++) {
			adMat[i] = std::vector<int>(tops);
			adMat[i][i] = INT32_MAX;
		}
	}
	Matrix() : Matrix(7) {
		adMat[0][0] = INT32_MAX;
		adMat[0][1] = 5;
		adMat[0][2] = 17;
		adMat[0][3] = 23;
		adMat[0][4] = 2;
		adMat[0][5] = 10;
		adMat[0][6] = 16;

		adMat[1][0] = 15;
		adMat[1][1] = INT32_MAX;
		adMat[1][2] = 9;
		adMat[1][3] = 10;
		adMat[1][4] = 19;
		adMat[1][5] = 3;
		adMat[1][6] = 31;

		adMat[2][0] = 24;
		adMat[2][1] = 9;
		adMat[2][2] = INT32_MAX;
		adMat[2][3] = 22;
		adMat[2][4] = 13;
		adMat[2][5] = 46;
		adMat[2][6] = 51;

		adMat[3][0] = 37;
		adMat[3][1] = 4;
		adMat[3][2] = 13;
		adMat[3][3] = INT32_MAX;
		adMat[3][4] = 26;
		adMat[3][5] = 41;
		adMat[3][6] = 20;

		adMat[4][0] = 6;
		adMat[4][1] = 14;
		adMat[4][2] = 15;
		adMat[4][3] = 27;
		adMat[4][4] = INT32_MAX;
		adMat[4][5] = 33;
		adMat[4][6] = 42;

		adMat[5][0] = 15;
		adMat[5][1] = 4;
		adMat[5][2] = 7;
		adMat[5][3] = 31;
		adMat[5][4] = 10;
		adMat[5][5] = INT32_MAX;
		adMat[5][6] = 8;

		adMat[6][0] = 11;
		adMat[6][1] = 21;
		adMat[6][2] = 34;
		adMat[6][3] = 17;
		adMat[6][4] = 9;
		adMat[6][5] = 43;
		adMat[6][6] = INT32_MAX;
	}

	int get_tops() { return adMat.size(); }

	std::vector<std::pair<int, int>>& pathways() {
		static std::vector<std::pair<int, int>> paths;
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
						backup[i][j] = -(minl + minc);
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

					if (i == paths.back().first)
						backup[i][j] = INT32_MAX;

					if (j == paths.back().second)
						backup[i][j] = INT32_MAX;

					if (backup[i][j] < 0)
						backup[i][j] = 0;
				}
			backup[maxScore_c][maxScore_l] = INT32_MAX;
		}
		return paths;
	}

	std::vector<int> getPath(int start) {
		if (start >= 0 && start < adMat.size()) {
			std::vector<std::pair<int, int>> ways = pathways();
			std::vector<int> path(adMat.size() + 1);
			bool f;

			for (int i = 0; i < path.size(); i++) {
				f = false;
				for (int j = 0; j < ways.size() && !f; j++)

					if (ways[j].first == start) {
						path[i] = start;
						start = ways[j].second;
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

	Node(const sf::String& text, const Font& type, const int& size) {
		this->note = Text(L"" + text, type, size);
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
			nodes[i] = Node(titles[i], typeFace, size);

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
};

void showMatrix(std::vector<std::vector<int>>& mtrx) {
	std::cout << std::endl;
	std::cout << "\t";

	for (int i = 0; i < mtrx.size(); i++)
		std::cout << i + 1 << '\t';
	std::cout << std::endl;

	for (int i = 0; i < mtrx.size(); i++) {
		std::cout << i + 1 << "\t";
		for (int j = 0; j < mtrx.size(); j++) {

			if (mtrx[i][j] == INT32_MAX)
				std::cout << 'M' << "\t";
			else std::cout << mtrx[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	Matrix adjMat;
	std::vector<int> vec;
	int sum;
	std::vector<std::pair<int, int>> paths = adjMat.pathways();

	for_each(paths.begin(), paths.end(), [](std::pair<int, int>& it) {std::cout << it.first + 1 << "\t" << it.second + 1 << std::endl; });
	vec = adjMat.getPath(5);

	for (auto iter = vec.begin(); iter < vec.end(); ++iter)
		std::cout << *iter + 1 << "->";
	std::cout << "end";

	sum = adjMat.getSum(paths);
	std::cout << "\nОптимальная длина пути: " << sum;

	ContextSettings settings;
	settings.antialiasingLevel = 9;
	typeface.loadFromFile("tahoma.ttf");
	RenderWindow window(VideoMode(win_w, win_h), "Graph", sf::Style::Close | sf::Style::Titlebar, settings);

	std::vector<std::wstring> names = { L"1", L"2", L"3", L"4", L"5", L"6", L"7"};
	std::vector<std::vector<int>> mtrx = {
		std::vector<int>{INT32_MAX, 5, 17, 23, 2, 10, 16},
		std::vector<int>{15, INT32_MAX, 9, 10, 19, 3, 31},
		std::vector<int>{24, 9, INT32_MAX, 22, 13, 46, 51},
		std::vector<int>{37, 4, 13, INT32_MAX, 26, 41, 20},
		std::vector<int>{6, 14, 15, 27, INT32_MAX, 33, 42},
		std::vector<int>{5, 4, 7, 31, 10, INT32_MAX, 8},
		std::vector<int>{11, 21, 34, 17, 9, 43, INT32_MAX} };
	Graph gr(mtrx, names, typeface, 14);
	Node* displace = nullptr;
	Edge rib(10, 7, 14);

	showMatrix(mtrx);

	gr.paintRightWay();

	while (window.isOpen()) {
		Event evnt;

		while(window.pollEvent(evnt))
			if (evnt.type == Event::Closed) window.close();

		window.clear(Color::Black);

		gr.ConnectNE();

		for (int i = 0; i < gr.ribs.size(); i++)
			window.draw(gr.ribs[i]);
		for (int i = 0; i < gr.nodes.size(); i++)
			window.draw(gr.nodes[i]);/

		window.display();
	}
	return 0;
}