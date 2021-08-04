NULL =

bin_SCRIPTS = \
	bala-gen-introspect \
	$(NULL)

EXTRA_DIST = \
	bala-gen-introspect.in
	$(NULL)

if ENABLE_UNVERSIONED
install-exec-hook:
	cd $(DESTDIR)$(bindir) && $(LN_S) -f bala-gen-introspect@PACKAGE_SUFFIX@ bala-gen-introspect
endif
