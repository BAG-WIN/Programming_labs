/*
void algorithmWave(int N, int M, vector<vector<int>> &A,  vector<vector<int>> &list, int indexList)
{
    bool f = false;
    // ���������� �����:
    int i = list[indexList][1],
        j = list[indexList][2];
    // ��������, ��� ������� ������ - �� ������:
    if (A[i][j] == 1)
    {
        int k = list[indexList][0], // ���������� k ��� ������� ������
            i0 = list[indexList][3],
            j0 = list[indexList][4];
        A[i][j] = k + 1;
        // �������� ������������� �������, ����� �� ����� �� ������� �������,
        // � ��� �������� ������ �� �������� ���, �� ������� ������ �����.
        // �.�. �������� ������ ����� 4, �� ������ �� ��� �����������:
        if (i != N - 1 && i + 1 != i0)
        {
            list.push_back({k + 1, i + 1, j, i, j}); // ��������� ���������� ������ � ������ ��� ��������
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
        // ���������� ��������� ��������� ������
        algorithmWave(N, M, A, list, indexList); // ������� ����� � ��������� ������
    }
}

*/