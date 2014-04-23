use ExtUtils::MakeMaker;
WriteMakefile(
    NAME         => 'Sub::Inline',
    VERSION_FROM => 'lib/Sub/Inline.pm',
    OBJECT       => q/$(O_FILES)/,
);
