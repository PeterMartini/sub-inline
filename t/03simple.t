use strict;
use warnings;
use Sub::Inline;

my @warnings;
$SIG{__WARN__} = sub { push @warnings, "@_"; };

use Test::More tests => 3;

my $result = eval 'inline sub twoscalars($bar, $baz){ print "$bar $baz\n";} 5';
is @warnings, 0, "No warnings";
is $@, "", "No errors declaring inline sub";
is $result, 5, "eval returned 5";
