/*
 * Implement a time-based key-value data structure that supports:

* Storing multiple values for the same key at specified time stamps
* Retrieving the key's value at a specified timestamp
* Implement the TimeMap class:

* TimeMap() Initializes the object.
* void set(String key, String value, int timestamp) Stores the key key with the
value value at the given time timestamp.
* String get(String key, int timestamp) Returns the most recent value of key if
set was previously called on it and the most recent timestamp for that key
prev_timestamp is less than or equal to the given timestamp (prev_timestamp <=
timestamp). If there are no values, it returns "".
* Note: For all calls to set, the timestamps are in strictly increasing order.

* Example 1:
* Input:
* ["TimeMap", "set", ["alice", "happy", 1], "get", ["alice", 1], "get",
["alice", 2], "set", ["alice", "sad", 3], "get", ["alice", 3]]
* Output:
* [null, null, "happy", "happy", null, "sad"]

* Explanation:
* TimeMap timeMap = new TimeMap();
* timeMap.set("alice", "happy", 1);  // store the key "alice" and value "happy"
along with timestamp = 1.
* timeMap.get("alice", 1);           // return "happy"
* timeMap.get("alice", 2);           // return "happy", there is no value stored
for timestamp 2, thus we return the value at timestamp 1.
* timeMap.set("alice", "sad", 3);    // store the key "alice" and value "sad"
along with timestamp = 3.
* timeMap.get("alice", 3);           // return "sad"
*/

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
class TimeMap {
public:
  std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>
      store;

  TimeMap() {}

  void set(std::string key, std::string value, int timestamp) {
    store[key].emplace_back(value, timestamp);
  }

  std::string get(std::string key, int timestamp) {
    auto &values = store[key];
    int left = 0, right = values.size() - 1;
    std::string res = "";

    while (left <= right) {
      int mid = (left + right) / 2;
      if (values[mid].second <= timestamp) {
        res = values[mid].first;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return res;
  }
};

int main() { return 0; }
