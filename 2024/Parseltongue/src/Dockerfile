# Use an official Python runtime as a parent image
FROM python:3.9-slim

# Set the working directory in the container
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Make the run.sh script executable
RUN chmod +x run.sh

# Run run.sh when the container launches
CMD ["./run.sh"]
