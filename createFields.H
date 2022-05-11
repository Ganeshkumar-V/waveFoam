volScalarField T
(
 IOobject
 (
  "T",
  runTime.timeName(),
  mesh,
  IOobject::MUST_READ,
  IOobject::AUTO_WRITE
 ),
 mesh
);

// Can be read from the file transportProperties //
IOdictionary transportProperties
(
 IOobject
 (
  "transportProperties",
  runTime.constant(),
  mesh,
  IOobject::MUST_READ_IF_MODIFIED,
  IOobject::NO_WRITE
 )
);

volVectorField u 
(
 IOobject
 (
 "u",
 runTime.timeName(),
 mesh,
 IOobject::MUST_READ,
 IOobject::AUTO_WRITE
 ),
 mesh
);

// Source Terms //

