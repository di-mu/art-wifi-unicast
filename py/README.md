# README for Python Online Optimization implementation
Optimizes current wifi and zigbee settings using numpy and scipy to manage and index datasheets.

## First time setup
Program needs to be run in a directory that contains the following files:
	* power_table.npy
	* prr_w.npy
	* prr_z.npy
If the above files do not exist, run genfile.py, which generates the above files (.npy files are numpy python arrays;
Python cannot parse .matlab or .xlsx files) using .mat structs (packaged or avaiable as PRR_4_compact.mat) or .csv files (packaged or available as power_table.csv). If the .mat or .csv files are updated, simply delete the .npy files and regenerate them. 

## Input/Output
Program currently contains modules that can be used seperately or together in the implementation:
	* f(x, y, prrw, prrz, Dt, hw, hz). Takes 7 inputs, returns/outputs D/G, the data transmission to throughput
	 ratio.
	* search(x,y,prrw,prrz,Dt,hw,hz). Again takes 7 inputs (calls f) and here ouputs three things:
	  ** (x,y), the optimized wifi and zigbee dB settings;
	  ** power_val, the corresponding power value from the power_table database;
	  ** val, the power_val multiplied by D/G, the data rate to goodput ratio (as specified by eq. 9 in
	     the paper).
	* search_test(x,y, prrw, prz, Dt, hw, hz). Same function as above, without the condition to test if the
	  current settings' ratio is above 0.9. Used to check results or debug.
The inputs are detailed below:
    	* x - Wifi dB value.
	* y - Zigbee dB value.
	* prrw - Current prrw settings.
	* prrz - Current prrz settings.
	* Dt - Data Transmission Rate.
	* hw - Throughput (Wifi).
	* hz - Throughput (Zigbee).

## Examples
An example input/output is shown below.
   > search_test(11,3,30,0,300,800,225)
   > ((12, 1), 1015.29, 297.5308665163102)

## Additional information
If you have any questions, please do not hesistate to contact me at nravicha@buffalo.edu.
I recommend having a virtualenv setup where you can install the numpy, scipy or related dependencies.

## Dependencies
Python package dependencies.
numpy==1.11.2
scipy==0.18.1
csv
