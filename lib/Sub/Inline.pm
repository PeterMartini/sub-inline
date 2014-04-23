package Sub::Inline;

use 5.014;
use XSLoader;
use Exporter;

our $VERSION = '0.01';
our @ISA = qw(Exporter);

# symbols to export on request
our @EXPORT_OK = ();

XSLoader::load __PACKAGE__, $VERSION;

1;

=head1 NAME

Sub::Inline - Add syntax to declare inline subs

=head1 VERSION

This document describes version 0.01 of Sub::Inline

=head1 SYNOPSIS

    use Sub::Inline;
    inline sub foo($a, $b) { $a + $b; }
    inline sub bar($a, $b) { return $a + $b; }

    my ($x, $y, $z);
    $x = foo($y,$z); # Compiles as $x = do { $y + $z }
    $x = bar($y,$z); # *Also* compiles as $x = do { $y + $z }

=head1 DESCRIPTION

This module adds syntax to declare inline subs.  Naturally, inline subs
do not allow the full range of functionality that a standard sub would,
including (but not limited to):

=over 4

=item * Closures are not allowed

=item * goto is not allowed

=item * eval is not allowed

=back

=head1 AUTHORS

Peter Martini E<lt>pcm@cpan.orgE<gt>.

=head1 COPYRIGHT

Copyright 2014 by Peter Martini E<lt>pcm@cpan.orgE<gt>.

This program is free software; you can redistribute it and/or 
modify it under the same terms as Perl itself.

See L<http://www.perl.com/perl/misc/Artistic.html>

=cut
