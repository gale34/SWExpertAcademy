#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*
 * Time complexity: TODO
 * Space complexity: TODO
 */

#define FRIEND 1
#define NOT_FRIEND 0
#define VISITED 1
#define NOT_VISITED 0
#define MAX_PEOPLE 100001

int count_group(vector<int> friendship[MAX_PEOPLE], vector<int> relationship_list, int* visited);

int main(int argc, const char *argv[]) {
    int N;
    cin >> N;

		vector<int> friendship[MAX_PEOPLE];
		int visited[MAX_PEOPLE] = {};
		vector<int> relationship_list;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >>y;
				relationship_list.push_back(x);
				friendship[x].push_back(y);
				friendship[y].push_back(x);
    }


		int answer = count_group(friendship, relationship_list, visited);
		printf("%d",answer);

    return 0;
}

int count_group(vector<int> friendship[MAX_PEOPLE], vector<int> relationship_list, int* visited)
{
	queue<int> f_queue;
	int answer = 0;

	for(int i = 0; i < relationship_list.size(); i++)
	{
		int target = relationship_list[i];

		if(visited[target] == NOT_VISITED)
		{
			f_queue.push(target);
			answer++;
		}

		while(!f_queue.empty())
		{
			int subTarget = f_queue.front();
			f_queue.pop();
			cout << subTarget << endl;
			visited[subTarget] = VISITED;

			for(int j = 0; j < friendship[subTarget].size(); j++)
			{
				int sub2Target = friendship[subTarget][j];
                cout << "@@" << sub2Target << endl;
				if(visited[sub2Target] == NOT_VISITED)
					f_queue.push(target);
			}
		}
		cout << "???" <<endl;
	}

	return answer;
}
