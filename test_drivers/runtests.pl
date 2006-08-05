#! /usr/bin/perl

$report_name = './report.txt';

# Create the report file
die if !open(REPORT, ">$report_name");

# First, build everything
print REPORT "==================Make output==================\n";
close($report_name);

`make >> $report_name`;
die if !open(REPORT, ">>$report_name");
print REPORT "==================End of Make output==================\n";
print REPORT "\n";
# Now, run individual tests and create the report
print REPORT "==================Smoke Test ==================\n";
close($report_name);
chdir 'smoke_test';
`./smoketest >> ../$report_name`;
chdir '..';
die if !open(REPORT, ">>$report_name");
print REPORT "==================End of smoke test==================\n";
print REPORT "\n";
print REPORT "==================Regression Test ==================\n"; 
close($report_name);
chdir 'regression_tests';
`./regressiontest >> ../$report_name`;
chdir '..';
die if !open(REPORT, ">>$report_name");
print REPORT "==================End of regression test==================\n";
print REPORT "\n";
print REPORT "==================Negative Test ==================\n"; 
close($report_name);
chdir 'negative';
`./negative >> ../$report_name`;
chdir '..';
die if !open(REPORT, ">>$report_name");
print REPORT "==================End of negative test==================\n";
print REPORT "\n";
