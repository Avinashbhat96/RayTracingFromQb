# Use an official base image with build tools
FROM mcr.microsoft.com/devcontainers/base:ubuntu-22.04

# Set environment variables to avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Set the system locale and keyboard layout configuration
RUN apt-get update && \
    apt-get install -y locales keyboard-configuration && \
    # Set the locale (example: en_US.UTF-8)
    locale-gen en_US.UTF-8 && \
    update-locale LANG=en_US.UTF-8 \
    # Configure keyboard layout (example: US)
    && echo "XKBMODEL=\"pc\"" > /etc/default/keyboard \
    && echo "XKBLAYOUT=\"us\"" >> /etc/default/keyboard \
    && echo "XKBVARIANT=\"\"" >> /etc/default/keyboard \
    && echo "XKBOPTIONS=\"\"" >> /etc/default/keyboard \
    && dpkg-reconfigure keyboard-configuration

# Install essential tools
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    git \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Install SDL2 and related libraries
RUN apt-get update && apt-get install -y \
    libsdl2-dev \
    libsdl2-image-dev \
    libsdl2-ttf-dev \
    libsdl2-mixer-dev \
    x11-xserver-utils \
    && rm -rf /var/lib/apt/lists/*

# Update package list and install software-properties-common
RUN apt-get update && \
    apt-get install -y software-properties-common

# Add the 'universe' repository
RUN add-apt-repository universe

RUN apt-get update && apt-get install -y \
    xserver-xorg-video-dummy \
    x11-apps \
    xorg \
    && rm -rf /var/lib/apt/lists/*


# Default working directory
WORKDIR /workspace

# Default shell
CMD [ "/bin/bash" ]
