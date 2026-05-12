# Copyright(c) The Maintainers of Nanvix.
# Licensed under the MIT License.

# =============================================================================
# nanvix/gcc
#
# Lightweight runtime image with Nanvix GCC cross-compiler for i686-nanvix.
#
# This image is built by the release workflow, which copies pre-built artifacts
# into docker-install/ before running `docker build`.
#
# Build (from release workflow):
#   docker build -t ghcr.io/nanvix/gcc:latest .
#
# Verify:
#   docker run --rm ghcr.io/nanvix/gcc:latest i686-nanvix-gcc --version
# =============================================================================

FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

# Install minimal runtime dependencies.
RUN apt-get update && apt-get install -y --no-install-recommends \
        ca-certificates \
        make \
    && rm -rf /var/lib/apt/lists/*

COPY docker-install/ /opt/nanvix/

ENV PATH="/opt/nanvix/bin:${PATH}"

# Smoke test.
RUN i686-nanvix-gcc --version && \
    i686-nanvix-as --version && \
    i686-nanvix-ld --version

LABEL org.opencontainers.image.source="https://github.com/nanvix/gcc" \
      org.opencontainers.image.description="Nanvix GCC cross-compilation toolchain (GCC, G++, Gfortran) for i686-nanvix"
