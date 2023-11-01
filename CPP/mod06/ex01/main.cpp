/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:14:05 by manwe             #+#    #+#             */
/*   Updated: 2023/10/13 19:19:15 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *pickaxce = new Data;
    Data *unknown;
    uintptr_t save;

    pickaxce->durability = 1500;
    pickaxce->item = "pickaxe";

    save = Serializer::serialize(pickaxce);

    unknown = Serializer::deserialize(save);

    if (pickaxce == unknown)
        std::cout << "the data struct was succsesfully serilized and deserialized!" << std::endl;
    else
        std::cout << "Opps not the same thing???" << std::endl;
     delete pickaxce;
}