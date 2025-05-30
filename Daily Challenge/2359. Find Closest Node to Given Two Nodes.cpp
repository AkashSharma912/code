class Solution {
public:
    vector<int> getDistances(const vector<int>& edges, int start) {
        int n = edges.size();
        vector<int> dist(n, -1);
        int current = start, d = 0;
        while (current != -1 && dist[current] == -1) {
            dist[current] = d;
            d++;
            current = edges[current];
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1 = getDistances(edges, node1);
        vector<int> dist2 = getDistances(edges, node2);

        int minDist = INT_MAX;
        int result = -1;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist || (maxDist == minDist && i < result)) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};