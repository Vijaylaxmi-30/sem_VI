# Event Registration System - Cloud Project

## Overview
A full-stack event registration system with a Node.js/Express backend and a React (Vite) frontend. Allows users to register for events and manage registrations.

## Setup Instructions

### Backend
1. Open a terminal and navigate to `cloud/Event_Registration_System/backend`.
2. Run `npm install` to install dependencies.
3. Create a `.env` file with your MongoDB connection string:
   ```
   MONGO_URI=your_mongodb_connection_string
   ```
4. Start the backend server:
   ```
   node server.js
   ```
   The backend runs on `http://localhost:5000` by default.

### Frontend
1. Open a new terminal and navigate to `cloud/Event_Registration_System/frontend`.
2. Run `npm install` to install dependencies.
3. Start the frontend development server:
   ```
   npm run dev
   ```
   The frontend runs on `http://localhost:5173` by default.

## Usage
- Open the frontend URL in your browser.
- Register for events and manage registrations.
- The frontend communicates with the backend API for all operations.

---

For any issues, check the browser console and backend terminal for errors.