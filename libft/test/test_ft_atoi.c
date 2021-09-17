/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:41:34 by haseo             #+#    #+#             */
/*   Updated: 2020/11/21 00:53:46 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//ft_atoi.c test file
#include "libft.h"

void main(void)
{
	printf("atoi : %d\n", atoi("2147483647"));
	printf("ft_atoi : %d\n", ft_atoi("2147483647"));
	printf("atoi : %d\n", atoi("42"));
	printf("ft_atoi : %d\n", ft_atoi("42"));
	printf("atoi : %d\n", atoi("2147483648"));
	printf("ft_atoi : %d\n", ft_atoi("2147483648"));
	printf("atoi : %d\n", atoi("2147483649"));
	printf("ft_atoi : %d\n", ft_atoi("2147483649"));
	printf("atoi : %d\n", atoi("2147483650"));
	printf("ft_atoi : %d\n", ft_atoi("2147483650"));
	printf("atoi : %d\n", atoi("-2147483648"));
	printf("ft_atoi : %d\n", ft_atoi("-2147483648"));
	printf("\n");
	printf("atoi : %d\n", atoi("-2147483649"));
	printf("ft_atoi : %d\n", ft_atoi("-2147483649"));
	printf("atoi : %d\n", atoi("–9223372036854775808"));
	printf("ft_atoi : %d\n", ft_atoi("–9223372036854775808"));
	printf("atoi : %d\n", atoi("9223372036854775807"));
	printf("ft_atoi : %d\n", ft_atoi("9223372036854775807"));
	printf("\n");
	printf("atoi : %d\n", atoi("1234567890123456789"));
	printf("ft_atoi : %d\n", ft_atoi("1234567890123456789"));
	printf("atoi : %d\n", atoi("12345678901234567890"));
	printf("ft_atoi : %d\n", ft_atoi("12345678901234567890"));
	printf("atoi : %d\n", atoi("123456789012345678901"));
	printf("ft_atoi : %d\n", ft_atoi("123456789012345678901"));
	printf("atoi : %d\n", atoi("12345678901234567890123456789"));
	printf("ft_atoi : %d\n", ft_atoi("12345678901234567890123456789"));
	printf("\n");
	printf("atoi : %d\n", atoi("-1234567890123456789"));
	printf("ft_atoi : %d\n", ft_atoi("-1234567890123456789"));
	printf("atoi : %d\n", atoi("-12345678901234567890"));
	printf("ft_atoi : %d\n", ft_atoi("-12345678901234567890"));
	printf("atoi : %d\n", atoi("-123456789012345678901"));
	printf("ft_atoi : %d\n", ft_atoi("-123456789012345678901"));
	printf("atoi : %d\n", atoi("-12345678901234567890123456789"));
	printf("ft_atoi : %d\n", ft_atoi("-12345678901234567890123456789"));

	printf("atoi : %d\n", atoi("0"));
	printf("ft_atoi : %d\n", ft_atoi("0"));
	printf("atoi : %d\n", atoi("-0"));
	printf("ft_atoi : %d\n", ft_atoi("-0"));
	printf("atoi : %d\n", atoi("000"));
	printf("ft_atoi : %d\n", ft_atoi("000"));
	printf("atoi : %d\n", atoi("0000000000000000000")); //0 19개
	printf("ft_atoi : %d\n", ft_atoi("0000000000000000000")); //0 19개
	printf("atoi : %d\n", atoi("00000000000000000000")); //0 20개
	printf("ft_atoi : %d\n", ft_atoi("00000000000000000000")); //0 20개
	printf("atoi : %d\n", atoi("000000000000000000000")); //0 21개
	printf("ft_atoi : %d\n", ft_atoi("000000000000000000000")); //0 21개
	printf("atoi : %d\n", atoi("-00000000000000000000")); //-,0 20개
	printf("ft_atoi : %d\n", ft_atoi("-00000000000000000000")); //-,0 20개
}
