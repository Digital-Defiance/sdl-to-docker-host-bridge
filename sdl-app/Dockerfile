FROM ubuntu:20.04

# Set environment variable to avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive



# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libssl-dev

# Clone and build libwebsockets
RUN git clone https://github.com/warmcat/libwebsockets.git && \
    cd libwebsockets && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install

# Copy the server source code into the container
COPY server.c .

# Build the server
RUN gcc -o server server.c -lwebsockets

# Set the entrypoint to run the server when the container starts
CMD ["./server"]

# Update the runtime linker configuration
ENV LD_LIBRARY_PATH=/usr/local/lib