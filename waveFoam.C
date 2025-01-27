/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2022 Ganeshkumar V, Ph.D Mechanical Engineering, IITGN
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    waveFoam

Description
    Solves Linear Advection Equation

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "pisoControl.H"
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    pisoControl piso(mesh);
    #include "createFields.H"	
    surfaceScalarField phi = fvc::flux(u);
    Info << "\nStarting time loop\n" << endl;
	
    while (runTime.loop())
    {
	Info << "Time = " << runTime.timeName() << nl << endl;
	#include "CourantNo.H"
    	
	// Governing Equation
	fvScalarMatrix TEqn(fvm::ddt(T) + fvm::div(phi, T));

	// Solving Governing Equation
	solve(TEqn);

	// Enforcing Boundary Condition
	T.correctBoundaryConditions();

	// Write Output
	runTime.write();
	//runTime.printExecutionTime(Info);
    }

    Info<< "End\n" << endl;

    return 0;
}
// ************************************************************************* //
