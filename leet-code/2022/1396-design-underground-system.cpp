// https://leetcode.com/problems/design-underground-system/
// Medium

class UndergroundSystem {
public:
    void checkIn(int id, string start_station, int start_time) {
        id_checkin[id] = {std::move(start_station), start_time};
    }

    void checkOut(int id, string end_station, int end_time) {
        auto start_it = id_checkin.find(id);
        auto [start_station, start_time] = std::move(start_it->second);
        auto trip = create_trip_name(std::move(start_station), std::move(end_station));
        trip_times[std::move(trip)].push_back(end_time - start_time);
        //id_checkin.erase(start_it); // seems to be a pessimisation
    }

    double getAverageTime(string start_station, string end_station) {
        auto trip = create_trip_name(std::move(start_station), std::move(end_station));
        auto& travel_times = trip_times[std::move(trip)];
        return std::reduce(travel_times.begin(), travel_times.end(), double(0))
            / travel_times.size();
    }

private:
    string create_trip_name(string start_station, string end_station) {
        auto& trip = start_station;
        trip.reserve(trip.size() + 1 + end_station.size());
        trip.push_back('-');
        trip.append(std::move(end_station));
        return std::move(trip); // maybe don't need to move
    }

    using CustomerId = int;
    using StationCheckin = std::pair<std::string, int>;
    std::unordered_map<CustomerId, StationCheckin> id_checkin;

    using Trip = std::string; // concatenation of start-station and end-station
    using TravelTimes = std::vector<int>;
    std::unordered_map<Trip, TravelTimes> trip_times;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

/*
Test data:
["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
[[],[45,"a",3],[32,"aa",8],[27,"a",10],[45,"ab",15],[27,"ab",20],[32,"b",22],["aa","b"],["a","ab"],[10,"a",24],["a","ab"],[10,"ab",38],["a","ab"]]
*/
