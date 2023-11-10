#include <iostream>
#include <vector>
using namespace std;


//-----------------------------------------------------------------������� � 1-� � 2-� �������--------------------------------------------------------------------

/*
-------������� ������������� ������� �����-------
    �������������� ����, �������������� � ���� ����
    ��������: ������ ������ vs � ������ ����� vw,
    � ���������� �������, ������ ������� �������
    ����� ���� ���� ����� ��������� ����� ���������.
*/
vector<vector<int>> transGraf(vector<vector<int>> vs, vector<vector<int>> vw, bool flag)
{
    int len = vs.size();
    if (flag)
        len++;

    vector<vector<int>> G (len, vector <int>(len));

    for (int i = 0; i < len - 1; i++)
    {
        int k = 0;
        if (vs[i].size() == 0)
        {
            for (int j = 0; j < len; j++)
            {
                if (G[i][j] == 0)
                {
                    G[i][j] = INT_MAX;
                }
            }
        }
        else
        {
            for (int j = 0; j < len; j++)
            {
                if (vs[i][k] == j + 1)
                {
                    G[i][j] = vw[i][k];
                    G[j][i] = vw[i][k];
                    if (k != vs[i].size() - 1)
                    {
                        k++;
                    }
                }
                else if (G[j][i] == 0)
                {
                    G[i][j] = INT_MAX;
                    G[j][i] = INT_MAX;
                }
            }
        }
    }
    return G;
}

/*
---------------�������� ��������-----------------
    v0 - ��������� �������
    vs - ������ ������ �����
    vw - ������ ����� ����� �����
    flag = true ���� ������������������� ����
*/
void algorithmDijkstra(int v0, vector<vector<int>> vs, vector<vector<int>> vw, bool flag)
{
    int len = vs.size();
    if (flag)
        len++;

    vector<bool> visited (len); // ������ ��������� ������
    vector<int> distances (len); // ������ ���������� �� v0 �� ������ ������ 
    int minW, mimI; // ����������� ��� � ����������� ������

    for (int i = 0; i < len; i++)
    {
        visited[i] = false;
        distances[i] = INT_MAX;
    }

    distances[v0 - 1] = 0;

    vector<vector<int>> A = transGraf(vs, vw, flag); // ������������� ������� ���������� �����
    for (int i = 0; i < len; i++)
    {
        A[i][i] = 0;
    }

    do
    {
        mimI = INT_MAX;
        minW = INT_MAX;

        for (int i = 0; i < len; ++i)
        {
            if (!visited[i] && distances[i] < minW)
            {
                mimI = i;
                minW = distances[i];
                break;
            }
        }

        if (mimI != INT_MAX)
        {
            for (int i = 0; i < len; ++i)
            {
                if (A[mimI][i] != INT_MAX && minW + A[mimI][i] < distances[i])
                {
                    distances[i] = minW + A[mimI][i];
                }
            }
            visited[mimI] = true;
        }
    } while (mimI < INT_MAX);

    // ����� ����������
    cout <<"\t���������� ���� �� ������� " << v0 << ":\n";
    for (int i = 0; i < len; i++)
    {
        if (i + 1 != v0)
        {
            cout << "\t\t�� ������� " << i + 1 << " ����������: " << distances[i] << '\n';
        }
    }
    cout << '\n';
}

/* 
---------------�������� ������--------------------
    v0 - ��������� �������
    vs - ������ ������ �����
    vw - ������ ����� ����� �����
    flag = true ���� ������������������� ����
*/
void algorithmFloyd(int v0, vector<vector<int>> vs, vector<vector<int>> vw, bool flag)
{
    int len = vs.size();
    if (flag)
        len++;

    vector<vector<int>> A = transGraf(vs, vw, flag); // ������������� ������� ���������� �����
    for (int i = 0; i < len; i++)
    {
        A[i][i] = 0;
    }

    for (int k = 0; k < len; k++)
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (A[i][k] == INT_MAX || A[k][j] == INT_MAX)
                    continue;

                if (i != k && j != k && i != j && A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
            }
        }
    }

    // ����� ����������
    cout << "\t���������� ���� �� ������� " << v0 << ":\n";
    for (int i = 0; i < len; i++)
    {
        if (i + 1 != v0)
        {
            cout << "\t\t�� ������� " << i + 1 << " ����������: " << A[v0 - 1][i] << '\n';
        }
    }
    cout << '\n';
}


//-----------------------------------------------------------------������� ��� 3-� ������-------------------------------------------------------------------------

/*
---------------�������� ��������------------------
    ��� ����������� ��������. ���� ������ ������
    ��� �� ��������, �� ��� ��������� ��������
    k + 1, ��� k - �������� ������, �� �������
    ������ "�����". ����� ����� ����������������
    � �������� ������ �� ����������� � ���������.

    list - ����, �������������� ������ ������,
    ���� ������ ���������������� �����. �����
    ���������������� ��������������� � �� ������,
    ������� ������� � ������.
    ������� ����� - ������ ����: {k, i, j, i0, j0}
    i, j - ���������� ������� ������
    i0, j0 - ���������� ������, �� ������� ������ �����
    k - ���������� �����
    pSize - ������ �����
*/
void algorithmWave(int N, int M, vector<vector<int>>& A, vector<vector<int>>& list, int indexList, int pSize)
{
    // ���������� ������ ����� ������ ����� �����:
    int i = list[indexList][1],
        j = list[indexList][2];
    // ��������, ��� ������� ������ - �� ������:
    if (A[i][j] == 1)
    {
        int k = list[indexList][0], // ���������� �������� k ��� ������� ������
            i0 = list[indexList][3], // ���������� ������, �� ������� ��������� �����
            j0 = list[indexList][4];
        A[i][j] = k + 1;
        // �������� ������������� �������, ����� �� ����� �� ������� �������,
        // � ��� �������� ������ �� �������� ���, �� ������� ������ �����.
        // �.�. �������� ������ ����� 4, �� ������ �� ��� �����������:
        if (i < N - pSize && i + 1 != i0)
        {
            bool f = true;
            for (int t = j; t < j + pSize - 1; t++)
            {
                if (A[i + pSize][t] == 0)
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                list.push_back({ k + 1, i + 1, j, i, j }); // ��������� ���������� ������ � ������ ��� ��������
            }
        }
        if (j < M - pSize && j + 1 != j0)
        {
            bool f = true;
            for (int t = i; t < i + pSize - 1; t++)
            {
                if (A[t][j + pSize] == 0)
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                list.push_back({ k + 1, i, j + 1, i, j });
            }
        }
        if (i != 0 && i - 1 != i0)
        {
            bool f = true;
            for (int t = j; t < j + pSize - 1; t++)
            {
                if (A[i - 1][t] == 0)
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                list.push_back({ k + 1, i - 1, j, i, j });
            }
        }
        if (j != 0 && j - 1 != j0)
        {
            bool f = true;
            for (int t = i; t < i + pSize - 1; t++)
            {
                if (A[t][j - 1] == 0)
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                list.push_back({ k + 1, i, j - 1, i, j });
            }
        }
    }

    indexList++;
    if (indexList < list.size())
    {
        // ���������� ��������� ��������� ������
        algorithmWave(N, M, A, list, indexList, pSize); // ������� ����� � ��������� ������
    }
}

/*
-----------------��������� �����------------------
    ������� ������ ��������� ������ "�����"
    �������� N �� M ������ �� ���������� ���������. 
    ���� �� ������� ����� ������ ������ ���������
    �� ������ ������, �� ����� ������������.
*/
void generateLake(int N, int M, vector<vector<int>> &A, int x)
{
    // �������� 0 �������� ������� �������
    // �������� 1 �������� ���������� �������
    // � ������ ������.

    srand(time(NULL)); // ������������� rand ��� �������� �������

    do {
        // ���������� ����� ���������:
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                A[i][j] = 1;
            }
        }
        // ��������� ��������� ��� x ��������:
        int t = 0;
        while (t != x)
        {
            // ��������� ��������� ���������:
            int i = rand() % N,
                j = rand() % M;
            if (A[i][j] == 1 && !(i == 0 && j == 0) && !(i == N - 1 && j == M - 1)) // ���� ��������������� ���������� �� �������� ������������ ������ � �����
            {
                A[i][j] = 0; // �������� ������ ��� ������
                t++;
            }
        }

        // ��������, ��� ����� ����������:
        vector<vector<int>> list = {{0, 0, 0, 0, 0}};
        algorithmWave(N, M, A, list, 0, 1);
    } 
    while (A[N - 1][M - 1] == 1); // ��������� ����������� �� ��� ���, ���� �� ����� ������ ������ �� ����� �����

    // ����� ������� �����:
    cout << "\n\t";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] != 0)
            {
                cout << ". ";
            }
            else
            {
                cout << "O ";
            }
        }
        cout << "\n\t";
    }
    cout << '\n';

    // ��������� ��������� (���� ����������):
    cout << "\t������������� ����� ������?[Y/N]\n\t";
    char c;
    cin >> c;
    if (c == 'Y' || c == 'y')
    {
        cout << "\t������� ���������� ��������:\n\t";
        cin >> x;
        generateLake(N, M, A, x);
    }
}

/*
-------������� ���������� ������������ ����--------
    ���������� ����������� ���� ��� ����������� �����
    � ������ pSize, � ����� ����� �� ���� ���������� �����. 
*/
int pathLake(int N, int M, vector<vector<int>> A, int pSize)
{
    if (pSize == 1)
    {
        return A[N - 1][M - 1] - 1;
    }
    else
    {
        // ��������, ��� ���� ����� ���������� �� ��������� �������:
        for (int i = 0; i < pSize; i++)
        {
            for (int j = 0; j < pSize; j++)
            {
                if (A[i][j] == 0)
                {
                    return 0;
                }
            }
        }

        // ��������, ��� ���� ����� ���������� �� �������� �������:
        for (int i = N - 1 - pSize; i < N - 1; i++)
        {
            for (int j = M - 1 - pSize; j < M - 1; j++)
            {
                if (A[i][j] == 0)
                {
                    return 0;
                }
            }
        }

        // ����������� ����� � �������� ���������:
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (A[i][j] != 0)
                {
                    A[i][j] = 1;
                }
            }
        }

        // ���������� ��������� ���������
        vector<vector<int>> list = { {0, 0, 0, 0, 0} };
        algorithmWave(N, M, A, list, 0, pSize);
        return A[N - pSize][M - pSize] - 1;
    }
}


//-----------------------------------------------------------------������� ��� 4-� ������-------------------------------------------------------------------------

/*
----------------������� � ���������-----------------
    ����������� �������. � ����� ������ �����������
    ����� �, � ��� � � � �����������, ��� �������
    ���������, ��������������� � ����� ������,
    �� ����� �������� ������. ���� ��� �������
    �����������, �� ������� �������� ���� ����,
    �� ������� ������ ���������� ������ �� ���� �����.
    ������� ������ �� ��������: �������� ��������
    stop, ������� ��������� �������������, �����
    ������ ��������� ����� � 100 ��������.
*/
void stringABC(vector<char> s, char c, bool &stop)
{
    if (s.size() < 100 && !stop)
    {
        s.push_back(c);
                 
        bool f = false; // �������������� ���������� ��� ������ �� �����
        // ������� ���� ������� �������� � ������ �� �������� ������� ������:
        for (int i = 1; i <= s.size() / 2; i++) // i - ����� ���������
        {
        
            f = false;
            for (int j = 0; j < i; j++)
            {
                // ���� ���� �� ���� ����� �� ���������, �� ��������� �� �����:
                if (s[s.size() - 2 * i + j] != s[s.size() - i + j])
                {
                    f = true;
                    break;
                }
            }
            // ���� ��� ����� �������, �� ��������� �����. ������� �����������:
            if (!f)
            {
                break;
            }
        }
        // ���� ������� ������� ��������� �� ����� �������� ���������, �� ����������� ��������� �����:
        if (f)
        {
            if (s.size() < 100)
            {
                stringABC(s, 'A', stop);
            }
            if (s.size() < 100 && !stop)
            {
                stringABC(s, 'B', stop);
            }
            if (s.size() < 100 && !stop)
            {
                stringABC(s, 'C', stop);
            }
            if (s.size() == 100)
            {
                // ����� ������ � � �������:
                stop = true;
                for (int i = 0; i < s.size(); i++)
                {
                    cout << s[i];
                }
                cout << ' ' << s.size() << "\n\n";
            }
        }
    }
}


//-----------------------------------------------------------------������� ��� 5-� ������-------------------------------------------------------------------------

/*
------������� ���������� ����� ������� ���������------   
*/
void roomName(vector<vector<int>>& A, int i, int j, vector<vector<int>>& roomCords, int& ind)
{
    int x0, y0;
    if (A[i + 1][j] == 1)
    {
        x0 = i + 1;
        y0 = j - 1;
    }
    else if (A[i - 1][j] == 1)
    {
        x0 = i - 3;
        y0 = j - 1;
    }
    else if (A[i][j - 1] == 1)
    {
        x0 = i - 1;
        y0 = j - 3;
    }
    else if (A[i][j + 1] == 1)
    {
        x0 = i - 1;
        y0 = j + 1;
    }
    while (A[x0 - 1][y0] != 0 || A[x0][y0 - 1] != 0)
    {
        if (A[x0 - 1][y0] != 0)
        {
            x0 -= 4;
        }
        else
        {
            y0 -= 4;
        }
    }
    bool f = true;
    for (int t = 0; t < roomCords.size(); t++)
    {
        if (x0 == roomCords[t][1] && y0 == roomCords[t][2])
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        roomCords.push_back({ ind, x0, y0 });
        ind++;
    }
}

/*
----------�������� �������� ��� ���������-------------
    ������� ����� � algorithmWave, �� ����� ��� ��������
    � �������� ������ ����������� �������� k, � �� k + 1.
    ��� �������� ����� � ����� ������� ��������� ��������
    k ������������� �� 1.
*/
void algorithmWaveLadirinth(int N, int M, vector<vector<int>>& A, vector<vector<int>>& list, int indexList, int x, int y, vector<vector<int>>& roomCords, int ind)
{
    int i = list[indexList][1],
        j = list[indexList][2];
    if (abs(A[i][j]) == 1)
    {
        int k = list[indexList][0], // ���������� �������� k ��� ������� ������
            i0 = list[indexList][3], // ���������� ������, �� ������� ��������� �����
            j0 = list[indexList][4];
        int m = (A[i][j] - 1) / 2;
        A[i][j] = k - m;
        if (i < N - 1 && i + 1 != i0)
        {
            if (abs(A[i + 1][j]) == 1)
            {
                list.push_back({ k - m, i + 1, j, i, j });
            }
        }
        if (j < M - 1 && j + 1 != j0)
        {
            if (abs(A[i][j + 1]) == 1)
            {
                list.push_back({ k - m, i, j + 1, i, j });
            }
        }
        if (i != 0 && i - 1 != i0)
        {
            if (abs(A[i - 1][j]) == 1)
            {
                list.push_back({ k - m, i - 1, j, i, j });
            }
        }
        if (j != 0 && j - 1 != j0)
        {
            if (abs(A[i][j - 1]) == 1)
            {
                list.push_back({ k - m, i, j - 1, i, j });
            }
        }

        if (m == -1)
        {
            roomName(A, i, j, roomCords, ind);
        }
    }

    indexList++;
    if (indexList < list.size() && A[x][y] == 1)
    {
        // ���������� ��������� ��������� ������
        algorithmWaveLadirinth(N, M, A, list, indexList, x, y, roomCords, ind); // ������� ����� � ��������� ������
    }
}

/*
---------������� ��������� ������ � ���������---------
*/
void roomGeneration(int N, int M, vector<vector<int>>& A)
{
    for (int i = 0; i < 20; i += 2)
    {
        int r = rand() % 4 + 1;
        //cout << r << ' ';
        switch (r)
        {
        case 1:
            if (int(i % 5 + 1) * 4 != 20)
            {
                A[int(i / 5) * 4 + 1][int(i % 5 + 1) * 4] = 1;
                A[int(i / 5) * 4 + 2][int(i % 5 + 1) * 4] = 1;
                A[int(i / 5) * 4 + 3][int(i % 5 + 1) * 4] = 1;
            }
            break;
        case 2:
            if (int(i % 5) * 4 != 0)
            {
                A[int(i / 5) * 4 + 2][int(i % 5) * 4] = 1;
                A[int(i / 5) * 4 + 3][int(i % 5) * 4] = 1;
                A[int(i / 5) * 4 + 1][int(i % 5) * 4] = 1;
            }
            break;
        case 3:
            if (int(i / 5 + 1) * 4 != 16)
            {
                A[int(i / 5 + 1) * 4][int(i % 5) * 4 + 1] = 1;
                A[int(i / 5 + 1) * 4][int(i % 5) * 4 + 2] = 1;
                A[int(i / 5 + 1) * 4][int(i % 5) * 4 + 3] = 1;
            }
            break;
        case 4:
            if (int(i / 5) * 4 != 0)
            {
                A[int(i / 5) * 4][int(i % 5) * 4 + 1] = 1;
                A[int(i / 5) * 4][int(i % 5) * 4 + 2] = 1;
                A[int(i / 5) * 4][int(i % 5) * 4 + 3] = 1;
            }
            break;
        default:
            break;
        }
    }
}

/*
----------������� ��������� ������� �� ������---------
*/
void exitGeneration(int N, int M, vector<vector<int>>& A)
{
    for (int i = 0; i < 20; i++)
    {
        int r = rand() % 4 + 1;
        switch (r)
        {
        case 1:
            if (int(i % 5 + 1) * 4 != 20 && A[int(i / 5) * 4 + 2][int(i % 5 + 1) * 4] == 0)
            {
                A[int(i / 5) * 4 + 2][int(i % 5 + 1) * 4] = -1;
            }
            break;
        case 2:
            if (int(i % 5) * 4 != 0 && A[int(i / 5) * 4 + 2][int(i % 5) * 4] == 0)
            {
                A[int(i / 5) * 4 + 2][int(i % 5) * 4] = -1;
            }
            break;
        case 3:
            if (int(i / 5 + 1) * 4 != 16 && A[int(i / 5 + 1) * 4][int(i % 5) * 4 + 2] == 0)
            {
                A[int(i / 5 + 1) * 4][int(i % 5) * 4 + 2] = -1;
            }
            break;
        case 4:
            if (int(i / 5) * 4 != 0 && A[int(i / 5) * 4][int(i % 5) * 4 + 2] == 0)
            {
                A[int(i / 5) * 4][int(i % 5) * 4 + 2] = -1;
            }
            break;
        default:
            break;
        }
    }
}

/*
----------������� ������ ��������� � �������----------
*/
void output(int N, int M, vector<vector<int>>& A, vector<vector<int>> &roomCoords)
{
    const char* names = "SABCDEFGHIJKLMNOPQRTU";
    int len = roomCoords.size() + 1;
    cout << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] == 0)
            {
                if (i % 4 == 0 && j % 4 != 0)
                {
                    cout << "--";
                }
                else if (!(i % 4 == 0 && j % 4 == 0))
                {
                    cout << '|';
                }
                else
                {
                    if (i > 0 && i < N - 1 && j > 0 && j < M - 1)
                    {
                        if (A[i - 1][j] == 0 && A[i + 1][j] == 0 && A[i][j - 1] != 0 && A[i][j - 1] != 0)
                            cout << '|';
                        else if (A[i - 1][j] != 0 && A[i + 1][j] != 0 && A[i][j - 1] == 0 && A[i][j + 1] == 0)
                            cout << '-';
                        else
                            cout << '+';
                    }
                    else if (i > 0 && i < N - 1)
                    {
                        if (A[i - 1][j] == 0 && A[i + 1][j] == 0)
                            cout << '|';
                    }
                    else if (j > 0 && j < M - 1)
                    {
                        if (A[i][j - 1] == 0 && A[i][j + 1] == 0)
                            cout << '-';
                    }
                    else
                    {
                        cout << '+';
                    }

                }
            }
            else
            {
                if (i % 4 == 1 && j % 4 == 1)
                {
                    bool f = true;
                    for (int t = 0; t < roomCoords.size(); t++)
                    {
                        if (i == roomCoords[t][1] && j == roomCoords[t][2])
                        {
                            if (A[roomCoords[t][1]][roomCoords[t][2]] == 2)
                            {
                                roomCoords[t][0] = 0;
                            }
                            cout << names[roomCoords[t][0]] << ' ';
                            f = false;
                            break;
                        }
                    }
                    if (f)
                    {
                        if (A[i][j] == 2)
                        {
                            bool f2 = true;
                            for (int t = 0; t < roomCoords.size(); t++)
                            {
                                if (roomCoords[t][0] == 0)
                                {
                                    cout << "  ";
                                    f2 = false;
                                    break;
                                }
                            }
                            if (f2)
                            {
                                roomCoords.push_back({ 0, i, j });
                                cout << names[0] << ' ';
                            }
                        }
                        else
                        {
                            if (A[i][j - 1] == 0 && A[i - 1][j] == 0)
                            {
                                if (j == 17)
                                {
                                    cout << names[len] << ' ';
                                    len++;
                                }
                                else if ((A[i - 1][j + 4] == 0) || (A[i - 1][j + 4] != 0 && A[i][j + 3] == 0))
                                {
                                    cout << names[len] << ' ';
                                    len++;
                                }
                                else
                                {
                                    cout << "  ";
                                }
                            }
                            else
                            {
                                cout << "  ";
                            }
                        }
                    }
                }
                else
                {
                    if (j % 4 != 0)
                    {
                        cout << "  ";
                    }
                    else
                    {
                        cout << ' ';
                    }
                }
            }

        }
        cout << '\n';
    }
}


/*
-------------������� ��������� ���������--------------
*/
void labyrinthGen()
{
    const char* names = "SABCDEFGHIJKLMNOPQRTU";

    // ��������� ������� ��������� � ���������� ������:
    int N = 17, M = 21, x = 0, y = 10;
    vector<vector<int>> A(N, vector<int>(M)); // ������� ���������
    char ans;
    do {

        srand(time(NULL)); // ������������� rand ��� �������� �������

        vector<vector<int>> roomCoords; // ������ ��������� �������� ������ ���� ������ ������

        // �������� �������������� ������� ���������:
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (i % 4 == 0 || j % 4 == 0)
                {
                    A[i][j] = 0;
                }
                else
                {
                    A[i][j] = 1;
                }
            }
        }
        A[16][10] = 1;
        A[x][y] = 1;

        // ��������� ������:
        roomGeneration(N, M, A);

        // ��������� ������� �� ������:
        exitGeneration(N, M, A);

        vector<vector<int>> list = { {2, 15, 10, 16, 10} };
        algorithmWaveLadirinth(N, M, A, list, 0, x, y, roomCoords, 1);

        // ����� ���������:
        output(N, M, A, roomCoords);

        if (A[x][y] - 1 == 0)
        {
            cout << "�� ��������� ������ �����\n\n";
        }
        else {
            if (A[x][y] - 1 < 5)
            {
                cout << "����������� ���� ����������: " << A[x][y] - 1 << " �������\n\n";
            }
            else
            {
                cout << "����������� ���� ����������: " << A[x][y] - 1 << " ������\n\n";
            }
        }

        cout << "������������� ����� ��������?[Y/N]\n\n";
        cin >> ans;

    }
    while (ans == 'Y' || ans == 'y');
    // ������� ������������ ��������:
    
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] == 0) cout << "* ";
            else if (A[i][j] == -1) cout << "- ";
            else cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}