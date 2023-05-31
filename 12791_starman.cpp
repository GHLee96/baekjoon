#include <cstring>
#include <iostream>
#include <map>

using namespace std;

multimap<int, string> m;

void preseet_db() {
    m.insert({1967, "DavidBowie"});
    m.insert({1969, "SpaceOddity"});
    m.insert({1970, "TheManWhoSoldTheWorld"});
    m.insert({1971, "HunkyDory"});
    m.insert({1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"});
    m.insert({1973, "AladdinSane"});
    m.insert({1973, "PinUps"});
    m.insert({1974, "DiamondDogs"});
    m.insert({1975, "YoungAmericans"});
    m.insert({1976, "StationToStation"});
    m.insert({1977, "Low"});
    m.insert({1977, "Heroes"});
    m.insert({1979, "Lodger"});
    m.insert({1980, "ScaryMonstersAndSuperCreeps"});
    m.insert({1983, "LetsDance"});
    m.insert({1984, "Tonight"});
    m.insert({1987, "NeverLetMeDown"});
    m.insert({1993, "BlackTieWhiteNoise"});
    m.insert({1995, "1.Outside"});
    m.insert({1997, "Earthling"});
    m.insert({1999, "Hours"});
    m.insert({2002, "Heathen"});
    m.insert({2003, "Reality"});
    m.insert({2013, "TheNextDay"});
    m.insert({2016, "BlackStar"});
}

void query(int s, int e) {
    int cnt = 0;
    for (int i = s; i <= e; i++) {
        cnt += m.count(i);
    }
    cout << cnt << endl;

    for (int i = s; i <= e; i++) {
        if (m.count(i) != 0) {
            auto iter = m.lower_bound(i);
            while (iter->first == i) {
                cout << i << " " << iter->second << endl;
                iter++;
            }
        }
    }
}

int main() {
    preseet_db();

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        int s, e;
        cin >> s >> e;
        query(s, e);
    }

    return 0;
}