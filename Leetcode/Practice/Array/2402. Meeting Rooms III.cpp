class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> roomsF(n, 0);
        queue<int> roomsUnused;
        vector<long long>roomsUsed(n, LLONG_MAX);

        for(int i = 0; i < n; i++) roomsUnused.push(i);

        for(auto meeting: meetings) {
            int room = n, earliestUsedRoom;
            long long earliest = LLONG_MAX;
            for(int i = n-1; i >= 0; i--) {
                if(roomsUsed[i] <= meeting[0]) room = i;
                else if(roomsUsed[i] != LLONG_MAX) {
                    long long timeGap = roomsUsed[i] - meeting[0];
                    if(timeGap <= earliest) earliest = timeGap, earliestUsedRoom = i;
                }
            }   
            if(!roomsUnused.empty() and roomsUnused.front() < room) room = roomsUnused.front();

            if(room != n) {
                roomsF[room]++;
                if(room == roomsUnused.front()) roomsUnused.pop();
                roomsUsed[room] = meeting[1];
            }
            else {
                roomsF[earliestUsedRoom]++;
                roomsUsed[earliestUsedRoom] += (meeting[1] - meeting[0]);
            } 
        }

        int maxUsed = -1, room = -1;
        for(int i = 0; i < n; i++) {
            if(roomsF[i] > maxUsed) maxUsed = roomsF[i], room = i;
        }

        return room;
    }
};