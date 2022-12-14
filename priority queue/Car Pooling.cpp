// https://leetcode.com/problems/car-pooling/

/*

There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
 

Constraints:

1 <= trips.length <= 1000
trips[i].length == 3
1 <= numPassengersi <= 100
0 <= fromi < toi <= 1000
1 <= capacity <= 105

*/


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<trips.size();i++){
            int cost=trips[i][0];
            int from=trips[i][1];
            int to=trips[i][2];
            pq.push({-from,{-1,cost}});
            pq.push({-to,{1,cost}});
        }

        int present=0;
        while(!pq.empty()){
            int start=pq.top().second.first;
            int cost=pq.top().second.second;
            pq.pop();
            present+=-start*cost;
            if(present>capacity) return 0;
        }
        return 1;
    }
};
