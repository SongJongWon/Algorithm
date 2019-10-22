#include <iostream>

#include <vector>

#include <queue>

#include <cstring> //memset

using namespace std;

 

const int MAX = 500;

const int INF = 987654321;

 

int N, M;

vector<pair<int, int>> graph[MAX];

//처음에는 최단거리에 해당하는 정점을 trace에 담는다

vector<pair<int, int>> trace[MAX];

bool visited[MAX][MAX];

 

vector<int> dijkstra(int start, int vertex)

{

        vector<int> distance(vertex, INF); //start를 기준으로 거리

        distance[start] = 0; //자기 자시한테 거는 비용 0

 

        priority_queue<pair<int, int>> pq; //Cost, Vertex;

        pq.push(make_pair(0, start)); //초기 비용과 시작점

 

        while (!pq.empty())

        {

                 int cost = -pq.top().first; //거리의 부호를 바꾸어 거리가 작은 정점부터 꺼내지게

                 int curVertex = pq.top().second;

                 pq.pop();

 

                 //최소거리를 원하므로

                 if (distance[curVertex] < cost)

                         continue;

 

                 //neighbor 다 확인

                 for (int i = 0; i < graph[curVertex].size(); i++)

                 {

                         int neighbor = graph[curVertex][i].first;

                         int neighborDistance = cost + graph[curVertex][i].second;

 

                         //거의 최단 거리를 찾기위해 삭제된 정점간의 간선을 무시한다

                         if (graph[curVertex][i].second == -1)

                                 continue;

 

                         //최소 경로 발견시 업데이트

                         if (distance[neighbor] > neighborDistance)

                         {

                                 distance[neighbor] = neighborDistance;

                                 //거리의 부호를 바꾸어 거리가 작은 정점부터 꺼내지도록 하기 위해

                                 pq.push(make_pair(-neighborDistance, neighbor));

 

                                 //trace 갱신

                                 trace[neighbor].clear();

                                 trace[neighbor].push_back(make_pair(curVertex, neighborDistance));

                         }

                         //최단 거리 찾을 때마다 trace update

                         else if (distance[neighbor] == neighborDistance)

                                 trace[neighbor].push_back(make_pair(curVertex, neighborDistance));

                 }

        }

        return distance;

}

 

void BFS(int destination)

{

        //queue를 이용하여 trace에 해당하는 정점들을 모두 지울 준비를 한다

        queue<int> q;

 

        q.push(destination);

        while (!q.empty())

        {

                 int curVertex = q.front();

                 q.pop();

 

                 for (int i = 0; i < trace[curVertex].size(); i++)

                 {

                         int neighbor = trace[curVertex][i].first;

                         if (visited[curVertex][neighbor])

                                 continue;

 

                         //원래 정점간 연결이 1->2라면 trace에는 2->1로 현재 연결되어 있기에

                         //graph[curVertex][]가 아닌 graph[neighbor][]로 봐야한다

                         //처음 들어오는 curVertex이 도착점임을 생각하면 쉽다

                         for (int i = 0; i < graph[neighbor].size(); i++)

                                 if (graph[neighbor][i].first == curVertex)

                                          graph[neighbor][i].second = -1;

 

                         q.push(neighbor);

                 }

        }

}

 

int main(void)

{

        while (1)

        {

                 memset(visited, false, sizeof(visited));

                 memset(trace, 0, sizeof(trace));

                 for (int i = 0; i < MAX; i++)

                         graph[i].clear();

 

                 cin >> N >> M;

                 if (N == 0 && M == 0)

                         break;

 

                 int S, D;

                 cin >> S >> D;

 

                 for (int i = 0; i < M; i++)

                 {

                         int source, destination, cost;

                         cin >> source >> destination >> cost;

 

                         graph[source].push_back(make_pair(destination, cost));

                 }

 

                 //처음 다익스트라를 통해 최단거리에 해당하는 정점을 trace에 담아온다

                 dijkstra(S, N);

                 //BFS를 이용하여 trace에 해당하는 정점들을 모두 지운다

                 BFS(D);

                 //거의 최단 거리를 구하기 위해 다시 다익스트라 이용

                 vector<int> result = dijkstra(S, N);

 

                 if (result[D] == INF)

                         cout << -1 << endl;

                 else

                         cout << result[D] << endl;

        }

        return 0;

}

