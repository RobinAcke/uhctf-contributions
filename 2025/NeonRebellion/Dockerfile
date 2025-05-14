# Use an official Python runtime as a parent image
FROM python:3.13-slim

# Set the working directory in the container
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Make sure that unzip is installed
RUN apt-get update && apt-get install -y unzip && rm -rf /var/lib/apt/lists/*

# Make the run.sh script executable
RUN chmod +x run.sh

# Expose the ports (frontend on 8080 and backend on 5000)
EXPOSE 8080 5000

# Run run.sh when the container launches
CMD ["./run.sh"]