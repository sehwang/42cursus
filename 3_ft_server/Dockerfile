# set the base image for the project-> debian buster
FROM	debian:buster

# add matadata on image
LABEL	maintainer="sehwang@student.42seoul.kr"

# execute shell commend and return commit
RUN	apt-get update 
RUN	apt-get install -y wget vim nginx mariadb-server php-mysql php-mbstring openssl php7.3-fpm

# copy files/dir from the HostOS to container 
COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp

# port for the container
EXPOSE	80 443

# start the container
CMD	bash run.sh
