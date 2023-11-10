#include <iostream>
#include <vector>
#include <chrono>


using namespace std;
using std::chrono::steady_clock;
using std::chrono::microseconds;


void algorithmFloyd(int v0, vector<vector<int>> vs, vector<vector<int>> vw, bool flag);
void algorithmDijkstra(int v0, vector<vector<int>> vs, vector<vector<int>> vw, bool flag);
void generateLake(int N, int M, vector<vector<int>> &A, int x);
int pathLake(int N, int M, vector<vector<int>> A, int p);
void stringABC(vector<char> s, char c, bool &stop);
void labyrinthGen();

using namespace std;

int main()
{
    steady_clock::time_point timeStart, timeStop;
    double timeResult;
    setlocale(LC_ALL, "russian");
    cout << "\t\tЛабораторная работа № 4\n\n";

//------------------------------------------ЗАДАНИЕ 1------------------------------------------------

    cout << "Задание 1\n\n";
    vector<vector<int>> vs1 = {
          {2, 5},
          {4, 7, 8},
          {4, 7},
          {5, 6},
          {},
          {7, 8},
          {8}
    };
    vector<vector<int>> vw1 = {
          {7, 6},
          {2, 4, 2},
          {4, 3},
          {5, 1},
          {},
          {4, 2},
          {5}
    };

    cout << "\tАлгоритм Дейкстры:\n\n";

    timeStart = steady_clock::now();
    algorithmDijkstra(1, vs1, vw1, true);
    timeStop = steady_clock::now();
    timeResult = std::chrono::duration_cast<microseconds>(timeStop - timeStart).count() / 1000.0;

    cout << "\n\tВремя выполнения алгоритма: " << timeResult << " мс\n\n";

    cout << "\tАлгоритм Флойда:\n\n";

    timeStart = steady_clock::now();
    algorithmFloyd(1, vs1, vw1, true);
    timeStop = steady_clock::now();
    timeResult = std::chrono::duration_cast<microseconds>(timeStop - timeStart).count() / 1000.0;

    cout << "\n\tВремя выполнения алгоритма: " << timeResult << " мс\n\n";
    
//------------------------------------------ЗАДАНИЕ 2------------------------------------------------

    cout << "Задание 2\n\n";
    vector<vector<int>> vs2 = {
         {4, 5, 6},
         {3, 4, 5, 6},
         {4, 5, 6},
         {},
         {}
    };
    vector<vector<int>> vw2 = {
         {5, 6, 9},
         {7, 8, 5, 8},
         {4, 5, 4},
         {},
         {}
    };
    algorithmFloyd(1, vs2, vw2, true);

//------------------------------------------ЗАДАНИЕ 3------------------------------------------------
    
   //cout << "Задание 3\n\n";
   //int M, N, x, pSize;
   //cout << "\tВведите размер озера по горизонтали:\n\t";
   //cin >> M;
   //cout << "\tВведите размер озера по вертикали:\n\t";
   //cin >> N;
   //vector<vector<int>> A(N, vector<int>(M));
   //cout << "\tВведите количество островов:\n\t";
   //cin >> x;
   //
   //generateLake(N, M, A, x);
   //cout << "\tВведите размер плота:\n\t";
   //cin >> pSize;
   //int p = pathLake(N, M, A, pSize);
   //if (p == 0)
   //{
   //    cout << "\tПлот размером " << pSize << " на " << pSize << " не может преодолеть озеро.\n";
   //}
   //else
   //{
   //    cout << "\tКратчайший путь: " << p << "\n\n";
   //}

//------------------------------------------ЗАДАНИЕ 4------------------------------------------------

    cout << "Задание 4\n\n";
    vector<char> s;
    s.push_back('A');
    bool stop = false;
    stringABC(s, 'B', stop);

//------------------------------------------ЗАДАНИЕ 5------------------------------------------------

    cout << "Задание 5\n\n";
    labyrinthGen();
    return 0;
}