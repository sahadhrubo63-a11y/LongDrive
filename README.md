# 🚗 LongDrive - Realistic Cross-Continent Driving Simulator

**LongDrive** A professional online multiplayer car driving simulator game. In this game, players can drive their favorite brand of cars in dynamic weather conditions (cloudy, rainy, night) in various realistic locations in Bangladesh, India and Europe.

## 🌐 Online & Architecture
* **Core Engine:** Unreal Engine 5 (UE5) for High-End Graphics & Physics.
* **Frontend Web/Lobby Portal:** HTML5, CSS3, and JavaScript.
* **Multiplayer System:** Dedicated Server with UE5 Networking.

## 📁 Repository Structure
├── .gitignore               # Unreal Engine temporary file filter
├── README.md                # Project Overview
├── WebPortal/               # Online Lobby and Player Dashboard
│   ├── index.html           # Main Web Interface
│   └── app.js               # Vehicle & Location Selection Logic
└── Source/                  # Unreal Engine C++ & Configuration
    ├── Vehicle/             # Car Physics and Interiors
    └── Network/             # Server connection logic
