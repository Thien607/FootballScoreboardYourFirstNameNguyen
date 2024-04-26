// Thien Nguyen
// Date: 4/24/2024
// COSC-1437-58002
// Professor: Tyson McMillan
// Description: This program will display a scoreboard for a football game.

#include <iostream>
#include <string>

using namespace std;

class Team {
private:
  string name;
  string coachName;
  string homeCity;
  bool homeStatus;
  int score;
  int timeoutCount;

public:
  // Constructor
  Team(string name, string coachName, string homeCity, bool homeStatus)
      : name(name), coachName(coachName), homeCity(homeCity),
        homeStatus(homeStatus), score(0), timeoutCount(3) {}

  // Getter and Setter functions
  string getName() const { return name; }
  void setName(const string &newName) { name = newName; }

  string getCoachName() const { return coachName; }
  void setCoachName(const string &newCoachName) { coachName = newCoachName; }

  string getHomeCity() const { return homeCity; }
  void setHomeCity(const string &newHomeCity) { homeCity = newHomeCity; }

  bool getHomeStatus() const { return homeStatus; }
  void setHomeStatus(bool newHomeStatus) { homeStatus = newHomeStatus; }

  int getScore() const { return score; }
  void setScore(int newScore) { score = newScore; }

  int getTimeoutCount() const { return timeoutCount; }
  void setTimeoutCount(int newTimeoutCount) { timeoutCount = newTimeoutCount; }
};

class Scoreboard {
private:
  Team team1;
  Team team2;

public:
  // Constructor
  Scoreboard(const Team &t1, const Team &t2) : team1(t1), team2(t2) {}

  // Getter functions for teams
  const Team &getTeam1() const { return team1; }
  const Team &getTeam2() const { return team2; }

  // Function to display the scoreboard
  void displayScoreboard() const {
    cout << "Scoreboard\n";
    cout << "----------------------------------\n";
    cout << "Home Team: " << team1.getName() << " (" << team1.getHomeCity()
         << ")\n";
    cout << "Coach: " << team1.getCoachName() << "\n";
    cout << "Score: " << team1.getScore() << "\n";
    cout << "Timeouts: " << team1.getTimeoutCount() << "\n";
    cout << "----------------------------------\n";
    cout << "Visitor Team: " << team2.getName() << " (" << team2.getHomeCity()
         << ")\n";
    cout << "Coach: " << team2.getCoachName() << "\n";
    cout << "Score: " << team2.getScore() << "\n";
    cout << "Timeouts: " << team2.getTimeoutCount() << "\n";
    cout << "----------------------------------\n";
  }

  // Function to update scores
  void updateScore(int teamNumber, int points) {
    if (teamNumber == 1) {
      int newScore = team1.getScore() + points;
      team1.setScore(newScore);
    } else if (teamNumber == 2) {
      int newScore = team2.getScore() + points;
      team2.setScore(newScore);
    } else {
      cout << "Invalid team number!\n";
    }
  }
};

int main() {
  // Create two instances of the Team class
  Team dallas("Dallas Cowboys", "Jason Garrett", "Dallas", true);
  Team houston("Houston Texans", "Bill O'Brien", "Houston", false);

  // Create an instance of the Scoreboard class
  Scoreboard scoreboard(dallas, houston);

  // Display initial scoreboard
  scoreboard.displayScoreboard();

  // Update scores
  scoreboard.updateScore(
      1, 7); // Update score for team 1 (Dallas Cowboys) by 7 points
  scoreboard.updateScore(
      2, 3); // Update score for team 2 (Houston Texans) by 3 points

  // Display updated scoreboard
  scoreboard.displayScoreboard();

  return 0;
}
