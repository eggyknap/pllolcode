# pllolcode Makefile $Id: Makefile,v 1.9 2009/05/04 15:04:55 eggyknap Exp $

MODULE_big = pllolcode
OBJS= pllolcode_lang.o pllolcode_scan.o pllolcode_symbol.o pllolcode.o pllolcode_exec.o

EXTRA_CLEAN = y.tab.c y.tab.h pllolcode_lang.c pllolcode_lang.h lex.yy.c pllolcode_lex.c pllolcode_scan.c gram.output

ifndef DONT_USE_PGXS
PGXS := $(shell pg_config --pgxs)
include $(PGXS)
else
subdir = contrib/pllolcode
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif

pllolcode_lang.o: $(srcdir)/pllolcode_lang.c
pllolcode_scan.o: $(srcdir)/pllolcode_scan.c

# See notes in src/backend/parser/Makefile about the following two rules

$(srcdir)/pllolcode_lang.c: $(srcdir)/pllolcode_lang.h ;

# $(YACC) -d $(YFLAGS) $<
$(srcdir)/pllolcode_lang.h: gram.y
ifdef YACC
	bison -vtd $<
	mv -f gram.tab.c $(srcdir)/pllolcode_lang.c || echo 
	mv -f gram.tab.h $(srcdir)/pllolcode_lang.h || echo
else
	@$(missing) bison $< $@
endif

$(srcdir)/pllolcode_scan.c: scan.l
ifdef FLEX
	$(FLEX) $(FLEXFLAGS) -o'$@' $<
else
	@$(missing) flex $< $@
endif

distprep: $(srcdir)/pllolcode_lang.c $(srcdir)/pllolcode_lang.h $(srcdir)/pllolcode_scan.c

maintainer-clean:
	rm -f $(srcdir)/pllolcode_lang.c $(srcdir)/pllolcode_lang.h $(srcdir)/pllolcode_scan.c

