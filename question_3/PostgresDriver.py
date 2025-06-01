import psycopg2
import json

# Database connection parameters
db_params = {
    'dbname': 'your_database_name',
    'user': 'your_username',
    'password': 'your_password',
    'host': 'your_database_host'
}

# Function to fetch data from the PostgreSQL table and return it as JSON


def fetch_user_data_as_json():
    try:
        # Connect to the PostgreSQL database
        conn = psycopg2.connect(**db_params)
        cursor = conn.cursor()

        # Execute a SELECT query
        cursor.execute(
            "SELECT user_id, name, age, phone FROM public.user_table")

        # Fetch all rows
        rows = cursor.fetchall()

        # Define a list to store the results
        results = []

        # Iterate through the rows and convert to JSON format
        for row in rows:
            user_id, name, age, phone = row
            user_data = {
                "user_id": user_id,
                "name": name,
                "age": age,
            }
            if phone:
                user_data["phone"] = phone
            results.append(user_data)

        # Create a JSON response
        response = {
            "status_code": 200,
            "data": results
        }

        # Print the JSON as a string
        user_data = json.dumps(response, indent=1, default=str)
        print(user_data)

    except psycopg2.Error as e:
        print("status_code:500")
        print(f"Error: {e}")
    finally:
        # Close the database connection
        if conn:
            conn.close()


# Call the function
fetch_user_data_as_json()
