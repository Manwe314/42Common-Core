all:
	@docker compose -f ./srcs/docker-compose.yml up -d --build
up: all

down:
	@docker compose -f ./srcs/docker-compose.yml down

re: clean all

clean:
	@docker stop $$(docker ps -qa)
	docker rm -f $$(docker ps -qa)
	docker rmi -f $$(docker images -qa)
	docker volume rm $$(docker volume ls -q)
	docker network rm srcs_inception

.PHONY: all re down clean
