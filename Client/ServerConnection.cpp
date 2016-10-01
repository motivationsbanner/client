#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "ServerConnection.h"

void ServerConnection::send() {
	sf::Clock clock;
	while (true) {
		data_mutex.lock();
		packet.clear();
		packet << last_received_command << x << y;

		if (socket.send(packet, recipient, port) != sf::Socket::Done) {
			throw std::exception("Failed to send packet");
		}
		data_mutex.unlock();

		sf::sleep(sf::seconds(SLEEP) - clock.restart());

	}
}


void ServerConnection::receive() {
	sf::IpAddress sender;
	unsigned short port;
	sf::Socket::Status status;
	sf::Packet packet;

	while (true) {
		packet.clear();
		status = socket.receive(packet, sender, port);

		if (status != sf::Socket::Done) {
			throw std::exception("Failed to receive packet");
		}

		sf::Uint8 CommandType;
		sf::Uint16 command_id, player_id, x, y;

		data_mutex.lock();
		do {
			packet >> CommandType;

			switch (CommandType) {
			case CommandType::player_join:
				packet >> command_id >> player_id >> x >> y;
				
				if (command_id > last_received_command) {
					last_received_command = command_id;

					new_players.push_back(player_id);

					players[player_id] = sf::Vector2<sf::Uint16>(x, y);
				}
				break;

			case CommandType::player_leave:
				packet >> command_id >> player_id;

				if (command_id > last_received_command) {
					last_received_command = command_id;

					disconnected_players.push_back(player_id);
				}
				break;
			}

		} while (CommandType != CommandType::null);

		while ((packet >> player_id >> x >> y)) {
			players[player_id] = sf::Vector2<sf::Uint16>(x, y);
		}
		data_mutex.unlock();
	}
}


void ServerConnection::setPosition(sf::Uint16 x, sf::Uint16 y) {
	this->x = x;
	this->y = y;
}

ServerConnection::ServerConnection(std::string adress, int port) {

	this->port = port;
	recipient = adress;

	if (socket.bind(sf::Socket::AnyPort) != sf::Socket::Done) {
		throw std::exception("Failed to bind socket");
	}

	thread_receive = new sf::Thread(&ServerConnection::receive, this);
	thread_receive->launch();

	thread_send = new sf::Thread(&ServerConnection::send, this);
	thread_send->launch();
}

ServerConnection::~ServerConnection() {
	thread_receive->terminate();
	free(thread_receive);

	thread_send->terminate();
	free(thread_send);
}

sf::Vector2<sf::Uint16> ServerConnection::getPlayerPosition(sf::Uint16 player_id) {
	data_mutex.lock();
	auto coords = players.at(player_id);
	data_mutex.unlock();

	return coords;
}

sf::Uint16 ServerConnection::popNewPlayer() {
	data_mutex.lock();
	
	sf::Uint16 player_id = NULL;
	
	if (new_players.size())
	{
		player_id = new_players.front();
		new_players.pop_front();
	}

	data_mutex.unlock();

	return player_id;
}

sf::Uint16 ServerConnection::popDisconnectedPlayer() {
	data_mutex.lock();

	sf::Uint16 player_id = NULL;

	if (disconnected_players.size())
	{
		player_id = disconnected_players.front();
		disconnected_players.pop_front();
	}

	data_mutex.unlock();

	return player_id;
}