# Tribes:Ascend Mods

This is the repository with the sources of the Tribes Ascend C++ SDK and mods.

## Dependencies

You need to provide Boost v1.68.0 and the Nlohmann JSON library.

You should set the following environment variables for these:
- TAMODS_BOOST_INCLUDE_PATH - Path to Boost (i.e. the main Boost directory)
- TAMODS_BOOST_LIB_PATH  - Path to compiled Boost libraries (usually <Boost dir>\stage\lib)
- TAMODS_NLOHMANNJSON_INCLUDE_PATH - Path to Nlohmann JSON include directory

## Releasing

To release a new version:

1. Bump the version in buildconfig.h (it's a float)
2. Build for release
3. Clone the release branch of https://github.com/mcoot/tamodsupdate/tree/release
4. Add the DLL to that repo, replacing TAMods.dll and copy it as TAMods-edge.dll and TAMods-beta.dll (these latter two can be used for preview release channels)
5. Update version.xml, updating the version associated with the files you changed
6. Commit and push that to release