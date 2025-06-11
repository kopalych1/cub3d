/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ANSI_colors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:58:28 by akostian          #+#    #+#             */
/*   Updated: 2025/03/03 06:49:45 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_COLORS_H
# define ANSI_COLORS_H

/* ========== Regular text ========== */

// Regular Black text
# define BLK "\033[0;30m"
// Regular Red text
# define RED "\033[0;31m"
// Regular Green text
# define GRN "\033[0;32m"
// Regular Yellow text
# define YEL "\033[0;33m"
// Regular Blue text
# define BLU "\033[0;34m"
// Regular Magenta text
# define MAG "\033[0;35m"
// Regular Cyan text
# define CYN "\033[0;36m"
// Regular White text
# define WHT "\033[0;37m"

/* ========== Regular bold text ========== */

// Regular Bold Black text
# define BBLK "\033[1;30m"
// Regular Bold Red text
# define BRED "\033[1;31m"
// Regular Bold Green text
# define BGRN "\033[1;32m"
// Regular Bold Yellow text
# define BYEL "\033[1;33m"
// Regular Bold Blue text
# define BBLU "\033[1;34m"
// Regular Bold Magenta text
# define BMAG "\033[1;35m"
// Regular Bold Cyan text
# define BCYN "\033[1;36m"
// Regular Bold White text
# define BWHT "\033[1;37m"

/* ========== Regular Underline text ========== */

// Regular Underline Black text
# define UBLK "\033[4;30m"
// Regular Underline Red text
# define URED "\033[4;31m"
// Regular Underline Green text
# define UGRN "\033[4;32m"
// Regular Underline Yellow text
# define UYEL "\033[4;33m"
// Regular Underline Blue text
# define UBLU "\033[4;34m"
// Regular Underline Mag text
# define UMAG "\033[4;35m"
// Regular Underline Cyan text
# define UCYN "\033[4;36m"
// Regular Underline White text
# define UWHT "\033[4;37m"

/* ========== Regular Background text ========== */

//Regular Background Black text
# define BLKB "\033[40m"
//Regular Background Red text
# define REDB "\033[41m"
//Regular Background Green text
# define GRNB "\033[42m"
//Regular Background Yellow text
# define YELB "\033[43m"
//Regular Background Blue text
# define BLUB "\033[44m"
//Regular Background Magenta text
# define MAGB "\033[45m"
//Regular Background Cyan text
# define CYNB "\033[46m"
//Regular Background White text
# define WHTB "\033[47m"

/* ========== High intensity text ========== */

//High intensity Black text
# define HBLK "\033[0;90m"
//High intensity Red text
# define HRED "\033[0;91m"
//High intensity Green text
# define HGRN "\033[0;92m"
//High intensity Yellow text
# define HYEL "\033[0;93m"
//High intensity Blue text
# define HBLU "\033[0;94m"
//High intensity Magenta text
# define HMAG "\033[0;95m"
//High intensity Cyan text
# define HCYN "\033[0;96m"
//High intensity White text
# define HWHT "\033[0;97m"

/* ========== High intensity Bold text ========== */

//High intensity Bold Black text
# define BHBLK "\033[1;90m"
//High intensity Bold Red text
# define BHRED "\033[1;91m"
//High intensity Bold Green text
# define BHGRN "\033[1;92m"
//High intensity Bold Yellow text
# define BHYEL "\033[1;93m"
//High intensity Bold Blue text
# define BHBLU "\033[1;94m"
//High intensity Bold Magenta text
# define BHMAG "\033[1;95m"
//High intensity Bold Cyan text
# define BHCYN "\033[1;96m"
//High intensity Bold White text
# define BHWHT "\033[1;97m"

/* ========== High intensity Background text ========== */

//High intensity Background Black text
# define BLKHB "\033[0;100m"
//High intensity Background Red text
# define REDHB "\033[0;101m"
//High intensity Background Green text
# define GRNHB "\033[0;102m"
//High intensity Background Yellow text
# define YELHB "\033[0;103m"
//High intensity Background Blue text
# define BLUHB "\033[0;104m"
//High intensity Background Magenta text
# define MAGHB "\033[0;105m"
//High intensity Background Cyan text
# define CYNHB "\033[0;106m"
//High intensity Background White text
# define WHTHB "\033[0;107m"

/* ========== Underline ========== */

//Underline text
# define UNDERLINE "\033[0;52m"
# define UNDERLINE_2 "\033[0;21m"

/* ========== Color reset ========== */

//Color reset
# define CRESET "\033[0m"
//Color reset
# define COLOR_RESET "\033[0m"

#endif