FROM debian:buster

RUN apt-get update && apt-get -y install wget

RUN apt-get install -y php7.3\
	php-fpm\
	php-mysql\
	mariadb-client

RUN wget https://wordpress.org/wordpress-6.4.2.tar.gz -P /var/www

RUN cd /var/www && tar -xzf wordpress-6.4.2.tar.gz && rm wordpress-6.4.2.tar.gz

RUN chown -R root:root /var/www/wordpress



RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
  && chmod +x wp-cli.phar \
  && mv wp-cli.phar /usr/local/bin/wp


COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
COPY ./tools/auto_config.sh /usr/local/bin


RUN mkdir /run/php



RUN chmod +x /usr/local/bin/auto_config.sh
ENTRYPOINT ["/usr/local/bin/auto_config.sh"]

WORKDIR /var/www/wordpress/

EXPOSE 9000

CMD ["/usr/sbin/php-fpm7.3", "-F"]
