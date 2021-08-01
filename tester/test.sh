# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 12:51:03 by graja             #+#    #+#              #
#    Updated: 2021/08/01 13:09:29 by graja            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

start=`date +%s`
cat $2|xargs -0 ../client $1
end=`date +%s`
echo Execution time was `expr $end - $start` seconds.
