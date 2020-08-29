#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] <= 0) continue;
			int color = picture[i][j];
			picture[i][j] = -color;
			number_of_area++;
			queue<pair<int, int>> q;

			int size = 1;
			q.push(make_pair(i, j));

			while (!q.empty()) {
				int cx = q.front().first;
				int cy = q.front().second;

				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = cx + dx[k];
					int ny = cy + dy[k];

					if ((nx >= 0) && (ny >= 0)
						&& (nx < m) && (ny < n)
						&& (picture[nx][ny] == color)) {
						picture[nx][ny] = -color;
						size++;
						q.push(make_pair(nx, ny));
					}
				}
			}

			if (max_size_of_one_area < size) max_size_of_one_area = size;
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	return answer;
}
