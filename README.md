Sub-Inline
=================

Create syntax for inline subs

Description
===========

After loading this module, the 'inline' modifier will be legal for sub definitions, such as:

```
inline sub foo() { print "Here\n";}
```

This definition creates a new sub foo with the special property that every time it is called in the normal manner (i.e., by name without a leading ampersand), the VM will insert the body of the sub instead of a call to the sub in the generated code.

In other words, when you write this:

```
foo();
```

the VM will turn it into the equivalent of this:

```
do { print "Here\n";}
```

When testing simple scripts, Deparse is very useful in debugging:

```
perl5.19.9 -Mblib -MSub::Inline-MO=Deparse -e 'inline sub foo(){print "Here\n";} foo;'
sub foo {
    print "Here\n";
}
;
;
print "Here\n";
-e syntax OK
```

(The extra ';'s should not be there; that will be fixed before release).

Open Issues
===========

This is currently just a proof of concept, plenty of open issues ...
