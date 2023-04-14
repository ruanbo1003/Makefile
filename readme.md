
### Makefile & multiple threads & network
* done
  * Makefile
  * multiple threads
  * write to file

* todo
  * network
  

### run
* build and run
  - make
  ```shell
  make
  ```
  - run
  ```shell
    ./bin/main
  ```
* build and run in shell script
  - run
  ```shell
  ./run.sh
  ```
* docker (base from ubuntu:23.04)
  - build base image
  ```shell
  docker build -t makefile_base:latest -f docker/Dockerfile-base .
  ```
  - build app image
  ```shell
  docker build -t makefile_app:latest -f docker/Dockerfile .
  ```
  - run
  ```shell
  docker run -it --rm makefile_app:latest
  ```
