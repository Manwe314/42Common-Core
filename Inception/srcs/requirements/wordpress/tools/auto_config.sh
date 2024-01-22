#!/bin/bash
sleep 10
if [ -f /var/www/wordpress/wp-config.php ]
then
    echo "Wordpress configuration already done"
else

	echo "Setting up wordpress"
   	
	wp config create --allow-root \
        --dbname="${MYSQL_DATABASE}" \
        --dbuser="${MYSQL_USER}" \
        --dbpass="${MYSQL_PASSWORD}" \
        --dbhost=mariadb:3306 \
        --path='/var/www/wordpress'

    wp core install --allow-root \
        --url="${DOMAIN_NAME}" \
        --title="${TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASS}" \
        --admin_email="${WP_ADMIN_MAIL}"

    wp user create --allow-root "${WP_USER}" "${WP_USER_MAIL}" \
        --user_pass="${WP_USER_PASS}"
fi


exec "$@"