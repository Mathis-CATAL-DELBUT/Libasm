#ifndef _LIBASM_H
# define _LIBASM_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char    *long_string = "cJM8%_&jwmf}$hzjt9?h{e&6VdqeTHcW{4#dzney*%m&Q/;TB-e7t+].jGTh+/(pH+fq(%b@1bWk}AygBXy@g{mgj#q%:/jypah#VNmDtHZtC=6u3Z=LHjS-N7?J[kughgY2f2{}-M1:NE.?}D?(3}D)b!$De%7.=K[ev**#p.*QSTaFZeqW5G0+Ce?,8uvc7ucY5A)8(PaWQMZxBg7pf)22w3V,?V&bkf}#jUxqFU,kteGwPcB*XfNJ[qL)J@7k9F$cLgA2m(prYiz)3+KQ1[@JCgRkzM=2}*Z/CETkvr@W!d{YDm%)b!K?HBT311749=Q(}p$@=637+2C;9fX8urPEMm(S}+g0#fLp$kh/?*3vCRxx[B!UnNfid-nkgyGyPm}eu0LrXc)[8U0}5Mht0,a:c2W{i&6!u3dL(BTK+Pn=84JiPpe6LE#-09;2zqaPLXDYRG_7kjw2mE8N#,E?WAp9e@J0Lrf/N=S:iVC_)%hew3V,5=n%6$*?uzg5.ax=%Yz:4k*Z16pc@Q-YCq2hmZ?4EJkDQ{rpz;U6(mBgpy08!cCr)Wi#2BpV2d:.4rbNx)K,=W:Pu*#9adJGurmKr$tDmr?F};@$%D}MKGw890wMRpTb}6QPevf!BvK.i677/zDYj2=XUauvT6SdB@S0TLq6-1j1=XyF#+a1S17!;YHzx2S1L[YwmbK1Q-37WAJGr*tQE#uew:Ur!WrM*Y0@phrD!y*nk+iJC6_Yd4cBPtA,ZZ-!f1:)v.$-{22Qv2fN#&.W7Ujr{}Erqa.uxyc_Nf;z?cVqZiu41@TbGQ!M=Y-(PMix$C?9J?m_qhHz_V,*V{_}+WVx#df{;B6N.03a)xwuELiyr=AJZ!rbF%D@uVyD3r3dg2SKx_wwT{(r.()?T/[;.kX,{a+]98Lk=BvwF5LWf%V6,a+S7-PdVJLk*6,@C4TWt]?g!x/;6#$dE$7L=;R[YLE}x(/Ghkvq1ZHL#[%05*ft;Nm5Cb:Cwi=t";

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(char *str);

#endif
