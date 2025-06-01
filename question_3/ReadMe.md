# PostgreSQL Driver for Python

This driver allows you to connect to a PostgreSQL database and retrieve data from a specified table. It returns the results in JSON string format. This README provides information on the development environment, SQL table creation, and instructions for using the driver.

## Development Environment

### Prerequisites

Before using this driver, ensure you have the following prerequisites installed:

- PostgreSQL: You need a PostgreSQL database installed and running. You can download PostgreSQL from [postgresql.org](https://www.postgresql.org/download/).

- Python 3.x: You can download Python from [python.org](https://www.python.org/downloads/).

- `psycopg2` library: This library is used to connect to PostgreSQL databases. You can install it using pip: pip install psycopg2

### Database Configuration

You will need the following database connection details:

- Database name (`dbname`)
- Username (`user`)
- Password (`password`)
- Host (`host`)
- Port (`port`)

Replace the placeholders in the script with your actual database connection parameters.

## SQL Table and Sample Data

You can create the necessary PostgreSQL table and insert sample data using the following SQL statements:

```sql
-- Postgresql table
CREATE TABLE IF NOT EXISTS public.user_table
(
  user_id numeric(10,0) NOT NULL,
  name character varying(50) COLLATE pg_catalog."default" NOT NULL,
  age numeric(3,0) NOT NULL,
  phone character varying(20) COLLATE pg_catalog."default",
  CONSTRAINT user_table_pkey PRIMARY KEY (user_id)
);

-- Insert sample data
INSERT INTO public.user_table (user_id, name, age, phone) VALUES (3, 'Jenny', 34, NULL);
INSERT INTO public.user_table (user_id, name, age, phone) VALUES (2, 'Tom', 29, '1-800-123-1234');
INSERT INTO public.user_table (user_id, name, age, phone) VALUES (1, 'John', 28, NULL);
```
