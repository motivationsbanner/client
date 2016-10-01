#pragma once
#include <deque>

#define SLEEP 0.05f

enum Direction : sf::Uint8 {
	none, up, down, left, right
};

enum CommandType : sf::Uint8 {
	null, player_join, player_leave, player_damage
};

class ServerConnection {
public:
	// Constructor
	ServerConnection(std::string adress, int port);
	
	// Destructor
	~ServerConnection();

	// Send the position of the player to the server
	void setPosition(sf::Uint16 x, sf::Uint16 y);

	// Returns the position of the player with the given id (self is 0)
	sf::Vector2<sf::Uint16> getPlayerPosition(sf::Uint16 player_id);

	// Returns the id of a new player or NULL (self doesn't recieve a JOIN-Command)
	sf::Uint16 popNewPlayer();

	// Returns the id of a disconnected player or NULL
	sf::Uint16 popDisconnectedPlayer();


private:
	sf::IpAddress recipient;
	int port;
	sf::Mutex data_mutex;
	sf::Packet packet;
	sf::UdpSocket socket;
	std::map<sf::Uint16, sf::Vector2<sf::Uint16>> players;
	sf::Thread *thread_receive;
	sf::Thread *thread_send;
	sf::Uint16 last_received_command = 0;
	std::deque<sf::Uint16> new_players;
	std::deque<sf::Uint16> disconnected_players;
	sf::Uint16 x = 0, y = 0;

	void receive();
	void send();
};