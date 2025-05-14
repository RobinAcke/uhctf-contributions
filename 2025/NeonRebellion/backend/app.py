# run with python3 app.py instead of flask run to properly intialize DB

from flask import Flask, request, jsonify
from flask_cors import CORS
import jwt
import sqlite3
from datetime import datetime, timedelta

app = Flask(__name__)
CORS(app)
SECRET_KEY = "MKUltra_3xP0s3_Th3S1gn!ngK3y#2025"

# Database setup
def get_db():
    conn = sqlite3.connect("ctf.db")
    conn.row_factory = sqlite3.Row
    return conn

# Initialize the database (run only once)
def initialize_db():
    with get_db() as db:
        # Check if the users table exists
        db.execute("""
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY,
            username TEXT,
            uuid TEXT,
            role TEXT
        )""")
        
        # Only insert data if the table is empty
        existing_users = db.execute("SELECT COUNT(*) FROM users").fetchone()[0]
        if existing_users == 0:
            db.execute("INSERT INTO users (id, username, uuid, role) VALUES (1, 'player', '56b1ba61-8299-4a64-9130-640a218fb4a1', 'user')")
            db.execute("INSERT INTO users (id, username, uuid, role) VALUES (2, 'test-user', '2d3c6916-f2e3-42fd-8d19-99f4341815b3', 'user')")
            db.execute("INSERT INTO users (id, username, uuid, role) VALUES (3, 'admin', 'd7ae5f8d-2a87-4c38-9f64-38ff5417c42e', 'site-admin-role-v2')")
            db.commit()

# JWT creation
def create_token(user_uuid, role):
    payload = {
        "user_uuid": user_uuid,
        "role": role,
        "exp": datetime.utcnow() + timedelta(hours=1)
    }
    return jwt.encode(payload, SECRET_KEY, algorithm="HS256")

# JWT verification
def verify_token(token):
    try:
        return jwt.decode(token, SECRET_KEY, algorithms=["HS256"])
    except jwt.ExpiredSignatureError:
        return None
    except jwt.InvalidTokenError:
        return None

@app.route("/login", methods=["POST"])
def login():
    data = request.json
    username, password = data.get("username"), data.get("password")

    # Hardcoded username - password
    if username == "player" and password == "MKI4lT4_3xP0s3th3Tru+h!":
        with get_db() as db:
            user = db.execute("SELECT * FROM users WHERE username = ?", (username,)).fetchone()
            if user:
                token = create_token(user["uuid"], user["role"])
                return jsonify({"token": token})

    return jsonify({"error": "Invalid credentials"}), 401

@app.route("/whoami", methods=["GET"])
def whoami():
    token = request.headers.get("Authorization", "").replace("Bearer ", "")
    decoded = verify_token(token)
    if not decoded:
        return jsonify({"error": "Token missing or invalid"}), 403
    
    return jsonify({"uuid": decoded.get("user_uuid")})


@app.route("/user/<identifier>", methods=["GET"])
def get_user(identifier):
    token = request.headers.get("Authorization", "").replace("Bearer ", "")
    decoded = verify_token(token)
    if not decoded:
        return jsonify({"error": "Token missing"}), 403

    with get_db() as db:
        user = db.execute(
            "SELECT id, username, uuid FROM users WHERE id = ? OR uuid = ?",
            (identifier, identifier)
        ).fetchone()
        if user:
            return jsonify(dict(user))
    return jsonify({"error": "User not found"}), 404

@app.route("/user/role/<uuid>", methods=["GET"])
def get_role(uuid):
    token = request.headers.get("Authorization", "").replace("Bearer ", "")
    decoded = verify_token(token)
    if not decoded:
        return jsonify({"error": "Token missing"}), 403

    with get_db() as db:
        user = db.execute("SELECT role FROM users WHERE uuid = ?", (uuid,)).fetchone()
        if user:
            return jsonify({"role": user["role"]})
    return jsonify({"error": "User not found"}), 404

@app.route("/flag", methods=["GET"])
def get_flag():
    token = request.headers.get("Authorization", "").replace("Bearer ", "")
    decoded = verify_token(token)

    if not decoded:
        return jsonify({"error": "Token missing"}), 403

    if decoded.get("role") == "site-admin-role-v2":
        return jsonify({"flag": "UHCTF{MK_Ultra_3xP0s3_Th3_TrUth!-9cf4ca70}"})

    return jsonify({"error": "Access denied. Incorrect role."}), 403

if __name__ == "__main__":
    # Initialize the database
    initialize_db()

    # Start the Flask app
    app.run(debug=True)
