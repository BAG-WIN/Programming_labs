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
    cout << "\t\t������������ ������ � 4\n\n";

//------------------------------------------������� 1------------------------------------------------

    cout << "������� 1\n\n";
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

    cout << "\t�������� ��������:\n\n";

    timeStart = steady_clock::now();
    algorithmDijkstra(1, vs1, vw1, true);
    timeStop = steady_clock::now();
    timeResult = std::chrono::duration_cast<microseconds>(timeStop - timeStart).count() / 1000.0;

    cout << "\n\t����� ���������� ���������: " << timeResult << " ��\n\n";

    cout << "\t�������� ������:\n\n";

    timeStart = steady_clock::now();
    algorithmFloyd(1, vs1, vw1, true);
    timeStop = steady_clock::now();
    timeResult = std::chrono::duration_cast<microseconds>(timeStop - timeStart).count() / 1000.0;

    cout << "\n\t����� ���������� ���������: " << timeResult << " ��\n\n";
    
//------------------------------------------������� 2------------------------------------------------

    cout << "������� 2\n\n";
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

//------------------------------------------������� 3------------------------------------------------
    
   //cout << "������� 3\n\n";
   //int M, N, x, pSize;
   //cout << "\t������� ������ ����� �� �����������:\n\t";
   //cin >> M;
   //cout << "\t������� ������ ����� �� ���������:\n\t";
   //cin >> N;
   //vector<vector<int>> A(N, vector<int>(M));
   //cout << "\t������� ���������� ��������:\n\t";
   //cin >> x;
   //
   //generateLake(N, M, A, x);
   //cout << "\t������� ������ �����:\n\t";
   //cin >> pSize;
   //int p = pathLake(N, M, A, pSize);
   //if (p == 0)
   //{
   //    cout << "\t���� �������� " << pSize << " �� " << pSize << " �� ����� ���������� �����.\n";
   //}
   //else
   //{
   //    cout << "\t���������� ����: " << p << "\n\n";
   //}

//------------------------------------------������� 4------------------------------------------------

    cout << "������� 4\n\n";
    vector<char> s;
    s.push_back('A');
    bool stop = false;
    stringABC(s, 'B', stop);

//------------------------------------------������� 5------------------------------------------------

    cout << "������� 5\n\n";
    labyrinthGen();
    return 0;
}