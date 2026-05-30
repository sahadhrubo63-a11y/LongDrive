-- GitHub Path: /Source/Network/UserSchema.sql
-- LongDrive Online Multiplayer Player Database Schema

CREATE TABLE IF NOT EXISTS Players (
    player_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    current_status VARCHAR(20) DEFAULT 'In Lobby',
    selected_brand VARCHAR(30) DEFAULT 'Toyota_SUV',
    selected_zone VARCHAR(50) DEFAULT 'BD_Bandarban',
    last_ping TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS MatchmakingLobby (
    lobby_id INT AUTO_INCREMENT PRIMARY KEY,
    server_ip VARCHAR(45) NOT NULL,
    active_players INT DEFAULT 1,
    weather_condition VARCHAR(30) DEFAULT 'Rainy_Cloudy',
    time_of_day VARCHAR(10) DEFAULT 'Night'
);
