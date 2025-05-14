#!/bin/bash

# Setup backend
echo "Setting up backend..."
cd backend/

# Create virtual environment if not exists
if [ ! -d "venv" ]; then
  python -m venv venv
fi

# Activate the virtual environment
source venv/bin/activate

# Install required packages
pip install -r requirements.txt

# Set Flask environment variables and run the server
export FLASK_APP=app.py
export FLASK_ENV=development
flask run --host=0.0.0.0 --port=5000 &

# Wait a little to make sure the backend starts before proceeding
sleep 2

# Go back to the root directory
cd ../

# Setup frontend (use Python's simple HTTP server)
echo "Setting up frontend..."
cd frontend/

# Unzip .git.zip to .git if .git doesn't exist
if [ ! -d ".git" ]; then
  echo "Secret internal setup process initiated."
  unzip .git.zip -d .git > /dev/null 2>&1
  echo "Secret internal setup process finished."
else
  echo "Secret internal setup already done. Skipping step."
fi

# Start the frontend server
echo "Starting frontend..."
python -m http.server 8080

# Cleanup and deactivate virtual environment upon script exit
trap "deactivate; echo 'Backend and frontend processes finished. Exiting.';" EXIT
