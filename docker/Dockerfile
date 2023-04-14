
FROM makefile_base:latest

WORKDIR /app/

ADD . /app/

# make
RUN make clean && make

# docker entrypoint
ENTRYPOINT ["/app/bin/main"]
