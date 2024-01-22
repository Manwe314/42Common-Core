FROM debian:buster

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install mariadb-server -y

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/mysql.sh /
RUN chmod +x /mysql.sh
CMD ["/mysql.sh"]