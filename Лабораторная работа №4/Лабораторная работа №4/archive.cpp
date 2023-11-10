/*
void algorithmWave(int N, int M, vector<vector<int>> &A,  vector<vector<int>> &list, int indexList)
{
    bool f = false;
    // координаты плота:
    int i = list[indexList][1],
        j = list[indexList][2];
    // проверка, что текущая клетка - не остров:
    if (A[i][j] == 1)
    {
        int k = list[indexList][0], // вычесление k для текущей клетки
            i0 = list[indexList][3],
            j0 = list[indexList][4];
        A[i][j] = k + 1;
        // проверка существование соседий, чтобы не выйти за границы массива,
        // и что соседняя клетка не является той, из которой пришла волна.
        // Т.к. соседних клеток всего 4, то каждая из них проверяется:
        if (i != N - 1 && i + 1 != i0)
        {
            list.push_back({k + 1, i + 1, j, i, j}); // добавляем координаты клетки в список для проверки
        }
        if (j != M - 1 && j + 1 != j0)
        {
            list.push_back({k + 1, i, j + 1, i, j});
        }
        if (i != 0 && i - 1 != i0)
        {
            list.push_back({k + 1, i - 1, j, i, j});
        }
        if (j != 0 && j - 1 != j0)
        {
            list.push_back({k + 1, i, j - 1, i, j});
        }
    }

    indexList++;
    if (indexList < list.size())
    {
        // вычисление координат следубщей клетки
        algorithmWave(N, M, A, list, indexList); // переход волны в следующую клетку
    }
}

*/