/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: Core_classes.h
# ========================================================================================= #
# Credits: uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL
# Thanks: HOOAH07, lowHertz
# Forums: www.uc-forum.com, www.gamedeception.net
#############################################################################################
*/

#ifdef _MSC_VER
    #pragma pack ( push, 0x4 )
#endif

/*
# ========================================================================================= #
# Constants
# ========================================================================================= #
*/

#define CONST_InvAspectRatio16x9                                 0.56249
#define CONST_InvAspectRatio5x4                                  0.8
#define CONST_InvAspectRatio4x3                                  0.75
#define CONST_AspectRatio16x9                                    1.77778
#define CONST_AspectRatio5x4                                     1.25
#define CONST_AspectRatio4x3                                     1.33333
#define CONST_INDEX_NONE                                         -1
#define CONST_UnrRotToDeg                                        0.00549316540360483
#define CONST_DegToUnrRot                                        182.0444
#define CONST_RadToUnrRot                                        10430.3783504704527
#define CONST_UnrRotToRad                                        0.00009587379924285
#define CONST_DegToRad                                           0.017453292519943296
#define CONST_RadToDeg                                           57.295779513082321600
#define CONST_Pi                                                 3.1415926535897932
#define CONST_MaxInt                                             0x7fffffff

/*
# ========================================================================================= #
# Enums
# ========================================================================================= #
*/

// Enum Core.Object.EDebugBreakType
enum EDebugBreakType
{
    DEBUGGER_NativeOnly                                = 0,
    DEBUGGER_ScriptOnly                                = 1,
    DEBUGGER_Both                                      = 2,
    DEBUGGER_MAX                                       = 3
};

// Enum Core.Object.EAutomatedRunResult
enum EAutomatedRunResult
{
    ARR_Unknown                                        = 0,
    ARR_OOM                                            = 1,
    ARR_Passed                                         = 2,
    ARR_MAX                                            = 3
};

// Enum Core.Object.EAspectRatioAxisConstraint
enum EAspectRatioAxisConstraint
{
    AspectRatio_MaintainYFOV                           = 0,
    AspectRatio_MaintainXFOV                           = 1,
    AspectRatio_MajorAxisFOV                           = 2,
    AspectRatio_MAX                                    = 3
};

// Enum Core.Object.EInterpCurveMode
enum EInterpCurveMode
{
    CIM_Linear                                         = 0,
    CIM_CurveAuto                                      = 1,
    CIM_Constant                                       = 2,
    CIM_CurveUser                                      = 3,
    CIM_CurveBreak                                     = 4,
    CIM_CurveAutoClamped                               = 5,
    CIM_MAX                                            = 6
};

// Enum Core.Object.EInterpMethodType
enum EInterpMethodType
{
    IMT_UseFixedTangentEvalAndNewAutoTangents          = 0,
    IMT_UseFixedTangentEval                            = 1,
    IMT_UseBrokenTangentEval                           = 2,
    IMT_MAX                                            = 3
};

// Enum Core.Object.EAxis
enum EAxis
{
    AXIS_NONE                                          = 0,
    AXIS_X                                             = 1,
    AXIS_Y                                             = 2,
    AXIS_BLANK                                         = 3,
    AXIS_Z                                             = 4,
    AXIS_MAX                                           = 5
};

// Enum Core.Object.ETickingGroup
enum ETickingGroup
{
    TG_PreAsyncWork                                    = 0,
    TG_DuringAsyncWork                                 = 1,
    TG_PostAsyncWork                                   = 2,
    TG_PostUpdateWork                                  = 3,
    TG_EffectsUpdateWork                               = 4,
    TG_MAX                                             = 5
};

// Enum Core.Object.EInputEvent
enum EInputEvent
{
    IE_Pressed                                         = 0,
    IE_Released                                        = 1,
    IE_Repeat                                          = 2,
    IE_DoubleClick                                     = 3,
    IE_Axis                                            = 4,
    IE_MAX                                             = 5
};

// Enum Core.Object.AlphaBlendType
enum AlphaBlendType
{
    ABT_Linear                                         = 0,
    ABT_Cubic                                          = 1,
    ABT_Sinusoidal                                     = 2,
    ABT_EaseInOutExponent2                             = 3,
    ABT_EaseInOutExponent3                             = 4,
    ABT_EaseInOutExponent4                             = 5,
    ABT_EaseInOutExponent5                             = 6,
    ABT_MAX                                            = 7
};

// Enum Core.DistributionVector.EDistributionVectorLockFlags
enum EDistributionVectorLockFlags
{
    EDVLF_None                                         = 0,
    EDVLF_XY                                           = 1,
    EDVLF_XZ                                           = 2,
    EDVLF_YZ                                           = 3,
    EDVLF_XYZ                                          = 4,
    EDVLF_MAX                                          = 5
};

// Enum Core.DistributionVector.EDistributionVectorMirrorFlags
enum EDistributionVectorMirrorFlags
{
    EDVMF_Same                                         = 0,
    EDVMF_Different                                    = 1,
    EDVMF_Mirror                                       = 2,
    EDVMF_MAX                                          = 3
};


/*
# ========================================================================================= #
# Classes
# ========================================================================================= #
*/

// Class Core.Object
// 0x003C
class UObject
{
public:
    //struct FPointer                                    VfTableObject;                                            // 0x0000 (0x0004) [0x0000000000821002]              ( CPF_Const | CPF_Native | CPF_EditConst | CPF_NoExport )
    int                                                ObjectInternalInteger;                                    // 0x0004 (0x0004) [0x0000000000821002]              ( CPF_Const | CPF_Native | CPF_EditConst | CPF_NoExport )
    struct FQWord                                      ObjectFlags;                                              // 0x0008 (0x0008) [0x0000000000021002]              ( CPF_Const | CPF_Native | CPF_EditConst )
    struct FPointer                                    HashNext;                                                 // 0x0010 (0x0004) [0x0000000000021002]              ( CPF_Const | CPF_Native | CPF_EditConst )
    struct FPointer                                    HashOuterNext;                                            // 0x0014 (0x0004) [0x0000000000021002]              ( CPF_Const | CPF_Native | CPF_EditConst )
    struct FPointer                                    StateFrame;                                               // 0x0018 (0x0004) [0x0000000000021002]              ( CPF_Const | CPF_Native | CPF_EditConst )
    class UObject*                                     Linker;                                                   // 0x001C (0x0004) [0x0000000000821002]              ( CPF_Const | CPF_Native | CPF_EditConst | CPF_NoExport )
    struct FPointer                                    LinkerIndex;                                              // 0x0020 (0x0004) [0x0000000000821002]              ( CPF_Const | CPF_Native | CPF_EditConst | CPF_NoExport )
    int                                                NetIndex;                                                 // 0x0024 (0x0004) [0x0000000000821002]              ( CPF_Const | CPF_Native | CPF_EditConst | CPF_NoExport )
    class UObject*                                     Outer;                                                    // 0x0028 (0x0004) [0x0000000000021002]              ( CPF_Const | CPF_Native | CPF_EditConst )
    struct FName                                       Name;                                                     // 0x002C (0x0008) [0x0000000000021003]              ( CPF_Edit | CPF_Const | CPF_Native | CPF_EditConst )
    class UClass*                                      Class;                                                    // 0x0034 (0x0004) [0x0000000000021002]              ( CPF_Const | CPF_Native | CPF_EditConst )
    class UObject*                                     ObjectArchetype;                                          // 0x0038 (0x0004) [0x0000000000021003]              ( CPF_Edit | CPF_Const | CPF_Native | CPF_EditConst )

private:
    static UClass* pClassPointer;

public:
    static TArray< UObject* >* GObjObjects(); 

    char* GetName(); 
    std::string GetNameCPP(); 
    std::string GetFullName(); 

    std::string GetStringClassName();
    std::string GetStringName();
    std::string GetStringFullName();

    static void splitFullName(const std::string& ObjectFullName,
        std::string& className,
        std::string& outerOuterName,
        std::string& outerName,
        std::string& objectName)
    {
        auto space = ObjectFullName.find_first_of(' ');
        auto afterSpace = space + 1;
        auto firstDot = ObjectFullName.find_first_of('.', afterSpace);
        auto afterFirstDot = firstDot + 1;
        auto secondDot = ObjectFullName.find_first_of('.', afterFirstDot);
        
        className = ObjectFullName.substr(0, space);
        if (secondDot == std::string::npos)
        {
            outerOuterName = "";
            outerName = ObjectFullName.substr(afterSpace, firstDot - afterSpace);
            objectName = ObjectFullName.substr(afterFirstDot);
        }
        else
        {
            auto afterSecondDot = secondDot + 1;
            outerOuterName = ObjectFullName.substr(afterSpace, firstDot - afterSpace);
            outerName = ObjectFullName.substr(afterFirstDot, secondDot - afterFirstDot);
            objectName = ObjectFullName.substr(afterSecondDot);
        }
    }

    template< class T > static T* FindObject ( const char* ObjectFullName ) 
    {
        while ( ! UObject::GObjObjects() ) 
            Sleep ( 100 ); 
    
        while ( ! FName::Names() ) 
            Sleep( 100 ); 

        std::string className, outerOuterName, outerName, objectName;
        splitFullName(ObjectFullName, className, outerOuterName, outerName, objectName);

        for (int i = 0; i < UObject::GObjObjects()->Count; ++i)
        {
            UObject* Object = UObject::GObjObjects()->Data[i];

            // skip no T class objects 
            if 
            ( 
                    ! Object 
                ||    ! Object->IsA ( T::StaticClass() ) 
            ) 
                continue; 

            // check 

            if(!_stricmp(className.c_str(), Object->Class->GetName()) &&
               (!Object->Outer->Outer || !_stricmp(outerOuterName.c_str(), Object->Outer->Outer->GetName())) &&
               !_stricmp(outerName.c_str(), Object->Outer->GetName()) &&
               !_stricmp(objectName.c_str(), Object->GetName()))
                return (T*)Object;
        }

        return NULL; 
    } 
    
    static UClass* FindClass ( char* ClassFullName ); 
    static TArray<UClass*> FindAllDuplicateClasses(const char* ClassFullName);

    bool IsA ( UClass* pClass ); 

    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1 ];

        return pClassPointer;
    };

    int GetBuildChangelistNumber ( );
    int GetEngineVersion ( );
    void GetSystemTime ( int* Year, int* Month, int* DayOfWeek, int* Day, int* Hour, int* Min, int* Sec, int* MSec );
    struct FString TimeStamp ( );
    struct FVector TransformVectorByRotation ( struct FRotator SourceRotation, struct FVector SourceVector, unsigned long bInverse );
    struct FName GetPackageName ( );
    bool IsPendingKill ( );
    float ByteToFloat ( unsigned char inputByte, unsigned long bSigned );
    unsigned char FloatToByte ( float inputFloat, unsigned long bSigned );
    float UnwindHeading ( float A );
    float FindDeltaAngle ( float A1, float A2 );
    float GetHeadingAngle ( struct FVector Dir );
    void GetAngularDegreesFromRadians ( struct FVector2D* OutFOV );
    void GetAngularFromDotDist ( struct FVector2D DotDist, struct FVector2D* OutAngDist );
    bool GetAngularDistance ( struct FVector Direction, struct FVector AxisX, struct FVector AxisY, struct FVector AxisZ, struct FVector2D* OutAngularDist );
    bool GetDotDistance ( struct FVector Direction, struct FVector AxisX, struct FVector AxisY, struct FVector AxisZ, struct FVector2D* OutDotDist );
    struct FVector PointProjectToPlane ( struct FVector Point, struct FVector A, struct FVector B, struct FVector C );
    float PointDistToPlane ( struct FVector Point, struct FRotator Orientation, struct FVector Origin, struct FVector* out_ClosestPoint );
    float PointDistToSegment ( struct FVector Point, struct FVector StartPoint, struct FVector EndPoint, struct FVector* OutClosestPoint );
    float PointDistToLine ( struct FVector Point, struct FVector Line, struct FVector Origin, struct FVector* OutClosestPoint );
    bool GetPerObjectConfigSections ( class UClass* SearchClass, class UObject* ObjectOuter, int MaxResults, TArray< struct FString >* out_SectionNames );
    void StaticSaveConfig ( );
    void SaveConfig ( );
    class UObject* FindObject ( struct FString ObjectName, class UClass* ObjectClass );
    class UObject* DynamicLoadObject ( struct FString ObjectName, class UClass* ObjectClass, unsigned long MayFail );
    struct FName GetEnum ( class UObject* E, int I );
    void Disable ( struct FName ProbeFunc );
    void Enable ( struct FName ProbeFunc );
    void eventContinuedState ( );
    void eventPausedState ( );
    void eventPoppedState ( );
    void eventPushedState ( );
    void eventEndState ( struct FName NextStateName );
    void eventBeginState ( struct FName PreviousStateName );
    void DumpStateStack ( );
    void PopState ( unsigned long bPopAll );
    void PushState ( struct FName NewState, struct FName NewLabel );
    struct FName GetStateName ( );
    bool IsChildState ( struct FName TestState, struct FName TestParentState );
    bool IsInState ( struct FName TestState, unsigned long bTestStateStack );
    void GotoState ( struct FName NewState, struct FName Label, unsigned long bForceEvents, unsigned long bKeepStack );
    bool IsUTracing ( );
    void SetUTracing ( unsigned long bShouldUTrace );
    struct FName GetFuncName ( );
    void DebugBreak ( int UserFlags, unsigned char DebuggerType );
    struct FString GetScriptTrace ( );
    void ScriptTrace ( );
    struct FString ParseLocalizedPropertyPath ( struct FString PathName );
    struct FString Localize ( struct FString SectionName, struct FString KeyName, struct FString PackageName );
    void WarnInternal ( struct FString S );
    void LogInternal ( struct FString S, struct FName Tag );
    struct FLinearColor Subtract_LinearColorLinearColor ( struct FLinearColor A, struct FLinearColor B );
    struct FLinearColor Multiply_LinearColorFloat ( struct FLinearColor LC, float Mult );
    struct FLinearColor ColorToLinearColor ( struct FColor OldColor );
    struct FLinearColor MakeLinearColor ( float R, float G, float B, float A );
    struct FColor LerpColor ( struct FColor A, struct FColor B, float Alpha );
    struct FColor MakeColor ( unsigned char R, unsigned char G, unsigned char B, unsigned char A );
    struct FColor Add_ColorColor ( struct FColor A, struct FColor B );
    struct FColor Multiply_ColorFloat ( struct FColor A, float B );
    struct FColor Multiply_FloatColor ( float A, struct FColor B );
    struct FColor Subtract_ColorColor ( struct FColor A, struct FColor B );
    struct FVector2D EvalInterpCurveVector2D ( struct FInterpCurveVector2D Vector2DCurve, float InVal );
    struct FVector EvalInterpCurveVector ( struct FInterpCurveVector VectorCurve, float InVal );
    float EvalInterpCurveFloat ( struct FInterpCurveFloat FloatCurve, float InVal );
    struct FVector2D vect2d ( float InX, float InY );
    float GetMappedRangeValue ( struct FVector2D InputRange, struct FVector2D OutputRange, float Value );
    float GetRangePctByValue ( struct FVector2D Range, float Value );
    float GetRangeValueByPct ( struct FVector2D Range, float Pct );
    struct FVector2D SubtractEqual_Vector2DVector2D ( struct FVector2D B, struct FVector2D* A );
    struct FVector2D AddEqual_Vector2DVector2D ( struct FVector2D B, struct FVector2D* A );
    struct FVector2D DivideEqual_Vector2DFloat ( float B, struct FVector2D* A );
    struct FVector2D MultiplyEqual_Vector2DFloat ( float B, struct FVector2D* A );
    struct FVector2D Divide_Vector2DFloat ( struct FVector2D A, float B );
    struct FVector2D Multiply_Vector2DFloat ( struct FVector2D A, float B );
    struct FVector2D Subtract_Vector2DVector2D ( struct FVector2D A, struct FVector2D B );
    struct FVector2D Add_Vector2DVector2D ( struct FVector2D A, struct FVector2D B );
    struct FQuat Subtract_QuatQuat ( struct FQuat A, struct FQuat B );
    struct FQuat Add_QuatQuat ( struct FQuat A, struct FQuat B );
    struct FQuat QuatSlerp ( struct FQuat A, struct FQuat B, float Alpha, unsigned long bShortestPath );
    struct FRotator QuatToRotator ( struct FQuat A );
    struct FQuat QuatFromRotator ( struct FRotator A );
    struct FQuat QuatFromAxisAndAngle ( struct FVector Axis, float Angle );
    struct FQuat QuatFindBetween ( struct FVector A, struct FVector B );
    struct FVector QuatRotateVector ( struct FQuat A, struct FVector B );
    struct FQuat QuatInvert ( struct FQuat A );
    float QuatDot ( struct FQuat A, struct FQuat B );
    struct FQuat QuatProduct ( struct FQuat A, struct FQuat B );
    struct FVector MatrixGetAxis ( struct FMatrix TM, unsigned char Axis );
    struct FVector MatrixGetOrigin ( struct FMatrix TM );
    struct FRotator MatrixGetRotator ( struct FMatrix TM );
    struct FMatrix MakeRotationMatrix ( struct FRotator Rotation );
    struct FMatrix MakeRotationTranslationMatrix ( struct FVector Translation, struct FRotator Rotation );
    struct FVector InverseTransformNormal ( struct FMatrix TM, struct FVector A );
    struct FVector TransformNormal ( struct FMatrix TM, struct FVector A );
    struct FVector InverseTransformVector ( struct FMatrix TM, struct FVector A );
    struct FVector TransformVector ( struct FMatrix TM, struct FVector A );
    struct FMatrix Multiply_MatrixMatrix ( struct FMatrix A, struct FMatrix B );
    bool NotEqual_NameName ( struct FName A, struct FName B );
    bool EqualEqual_NameName ( struct FName A, struct FName B );
    bool IsA ( struct FName ClassName );
    bool ClassIsChildOf ( class UClass* TestClass, class UClass* ParentClass );
    bool NotEqual_InterfaceInterface ( class UInterface* A, class UInterface* B );
    bool EqualEqual_InterfaceInterface ( class UInterface* A, class UInterface* B );
    bool NotEqual_ObjectObject ( class UObject* A, class UObject* B );
    bool EqualEqual_ObjectObject ( class UObject* A, class UObject* B );
    struct FString PathName ( class UObject* CheckObject );
    TArray< struct FString > SplitString ( struct FString Source, struct FString Delimiter, unsigned long bCullEmpty );
    void ParseStringIntoArray ( struct FString BaseString, struct FString delim, unsigned long bCullEmpty, TArray< struct FString >* Pieces );
    void JoinArray ( TArray< struct FString > StringArray, struct FString delim, unsigned long bIgnoreBlanks, struct FString* out_Result );
    struct FString GetRightMost ( struct FString Text );
    struct FString Split ( struct FString Text, struct FString SplitStr, unsigned long bOmitSplitStr );
    struct FString Repl ( struct FString Src, struct FString Match, struct FString With, unsigned long bCaseSensitive );
    int Asc ( struct FString S );
    struct FString Chr ( int I );
    struct FString Locs ( struct FString S );
    struct FString Caps ( struct FString S );
    struct FString Right ( struct FString S, int I );
    struct FString Left ( struct FString S, int I );
    struct FString Mid ( struct FString S, int I, int J );
    int InStr ( struct FString S, struct FString T, unsigned long bSearchFromRight, unsigned long bIgnoreCase, int StartPos );
    int Len ( struct FString S );
    struct FString SubtractEqual_StrStr ( struct FString B, struct FString* A );
    struct FString AtEqual_StrStr ( struct FString B, struct FString* A );
    struct FString ConcatEqual_StrStr ( struct FString B, struct FString* A );
    bool ComplementEqual_StrStr ( struct FString A, struct FString B );
    bool NotEqual_StrStr ( struct FString A, struct FString B );
    bool EqualEqual_StrStr ( struct FString A, struct FString B );
    bool GreaterEqual_StrStr ( struct FString A, struct FString B );
    bool LessEqual_StrStr ( struct FString A, struct FString B );
    bool Greater_StrStr ( struct FString A, struct FString B );
    bool Less_StrStr ( struct FString A, struct FString B );
    struct FString At_StrStr ( struct FString A, struct FString B );
    struct FString Concat_StrStr ( struct FString A, struct FString B );
    struct FRotator MakeRotator ( int Pitch, int Yaw, int Roll );
    bool SClampRotAxis ( float DeltaTime, int ViewAxis, int MaxLimit, int MinLimit, float InterpolationSpeed, int* out_DeltaViewAxis );
    int ClampRotAxisFromRange ( int Current, int Min, int Max );
    int ClampRotAxisFromBase ( int Current, int Center, int MaxDelta );
    void ClampRotAxis ( int ViewAxis, int MaxLimit, int MinLimit, int* out_DeltaViewAxis );
    float RSize ( struct FRotator R );
    float RDiff ( struct FRotator A, struct FRotator B );
    int NormalizeRotAxis ( int Angle );
    struct FRotator RInterpTo ( struct FRotator Current, struct FRotator Target, float DeltaTime, float InterpSpeed, unsigned long bConstantInterpSpeed );
    struct FRotator RTransform ( struct FRotator R, struct FRotator RBasis );
    struct FRotator RSmerp ( struct FRotator A, struct FRotator B, float Alpha, unsigned long bShortestPath );
    struct FRotator RLerp ( struct FRotator A, struct FRotator B, float Alpha, unsigned long bShortestPath );
    struct FRotator Normalize ( struct FRotator Rot );
    struct FRotator OrthoRotation ( struct FVector X, struct FVector Y, struct FVector Z );
    struct FRotator RotRand ( unsigned long bRoll );
    struct FVector GetRotatorAxis ( struct FRotator A, int Axis );
    void GetUnAxes ( struct FRotator A, struct FVector* X, struct FVector* Y, struct FVector* Z );
    void GetAxes ( struct FRotator A, struct FVector* X, struct FVector* Y, struct FVector* Z );
    bool ClockwiseFrom_IntInt ( int A, int B );
    struct FRotator SubtractEqual_RotatorRotator ( struct FRotator B, struct FRotator* A );
    struct FRotator AddEqual_RotatorRotator ( struct FRotator B, struct FRotator* A );
    struct FRotator Subtract_RotatorRotator ( struct FRotator A, struct FRotator B );
    struct FRotator Add_RotatorRotator ( struct FRotator A, struct FRotator B );
    struct FRotator DivideEqual_RotatorFloat ( float B, struct FRotator* A );
    struct FRotator MultiplyEqual_RotatorFloat ( float B, struct FRotator* A );
    struct FRotator Divide_RotatorFloat ( struct FRotator A, float B );
    struct FRotator Multiply_FloatRotator ( float A, struct FRotator B );
    struct FRotator Multiply_RotatorFloat ( struct FRotator A, float B );
    bool NotEqual_RotatorRotator ( struct FRotator A, struct FRotator B );
    bool EqualEqual_RotatorRotator ( struct FRotator A, struct FRotator B );
    bool InCylinder ( struct FVector Origin, struct FRotator Dir, float Width, struct FVector A, unsigned long bIgnoreZ );
    float NoZDot ( struct FVector A, struct FVector B );
    struct FVector ClampLength ( struct FVector V, float MaxLength );
    struct FVector VInterpTo ( struct FVector Current, struct FVector Target, float DeltaTime, float InterpSpeed );
    bool IsZero ( struct FVector A );
    struct FVector ProjectOnTo ( struct FVector X, struct FVector Y );
    struct FVector MirrorVectorByNormal ( struct FVector InVect, struct FVector InNormal );
    struct FVector VRandCone2 ( struct FVector Dir, float HorizontalConeHalfAngleRadians, float VerticalConeHalfAngleRadians );
    struct FVector VRandCone ( struct FVector Dir, float ConeHalfAngleRadians );
    struct FVector VRand ( );
    struct FVector VSmerp ( struct FVector A, struct FVector B, float Alpha );
    struct FVector VLerp ( struct FVector A, struct FVector B, float Alpha );
    struct FVector Normal ( struct FVector A );
    float VSizeSq2D ( struct FVector A );
    float VSizeSq ( struct FVector A );
    float VSize2D ( struct FVector A );
    float VSize ( struct FVector A );
    struct FVector SubtractEqual_VectorVector ( struct FVector B, struct FVector* A );
    struct FVector AddEqual_VectorVector ( struct FVector B, struct FVector* A );
    struct FVector DivideEqual_VectorFloat ( float B, struct FVector* A );
    struct FVector MultiplyEqual_VectorVector ( struct FVector B, struct FVector* A );
    struct FVector MultiplyEqual_VectorFloat ( float B, struct FVector* A );
    struct FVector Cross_VectorVector ( struct FVector A, struct FVector B );
    float Dot_VectorVector ( struct FVector A, struct FVector B );
    bool NotEqual_VectorVector ( struct FVector A, struct FVector B );
    bool EqualEqual_VectorVector ( struct FVector A, struct FVector B );
    struct FVector GreaterGreater_VectorRotator ( struct FVector A, struct FRotator B );
    struct FVector LessLess_VectorRotator ( struct FVector A, struct FRotator B );
    struct FVector Subtract_VectorVector ( struct FVector A, struct FVector B );
    struct FVector Add_VectorVector ( struct FVector A, struct FVector B );
    struct FVector Divide_VectorFloat ( struct FVector A, float B );
    struct FVector Multiply_VectorVector ( struct FVector A, struct FVector B );
    struct FVector Multiply_FloatVector ( float A, struct FVector B );
    struct FVector Multiply_VectorFloat ( struct FVector A, float B );
    struct FVector Subtract_PreVector ( struct FVector A );
    float FInterpConstantTo ( float Current, float Target, float DeltaTime, float InterpSpeed );
    float FInterpTo ( float Current, float Target, float DeltaTime, float InterpSpeed );
    float FPctByRange ( float Value, float InMin, float InMax );
    float RandRange ( float InMin, float InMax );
    float FInterpEaseInOut ( float A, float B, float Alpha, float Exp );
    float FInterpEaseOut ( float A, float B, float Alpha, float Exp );
    float FInterpEaseIn ( float A, float B, float Alpha, float Exp );
    float FCubicInterp ( float P0, float T0, float P1, float T1, float A );
    int FCeil ( float A );
    int FFloor ( float A );
    int Round ( float A );
    float Lerp ( float A, float B, float Alpha );
    float FClamp ( float V, float A, float B );
    float FMax ( float A, float B );
    float FMin ( float A, float B );
    float FRand ( );
    float Square ( float A );
    float Sqrt ( float A );
    float Loge ( float A );
    float Exp ( float A );
    float Atan2 ( float A, float B );
    float Atan ( float A );
    float Tan ( float A );
    float Acos ( float A );
    float Cos ( float A );
    float Asin ( float A );
    float Sin ( float A );
    float Abs ( float A );
    float SubtractEqual_FloatFloat ( float B, float* A );
    float AddEqual_FloatFloat ( float B, float* A );
    float DivideEqual_FloatFloat ( float B, float* A );
    float MultiplyEqual_FloatFloat ( float B, float* A );
    bool NotEqual_FloatFloat ( float A, float B );
    bool ComplementEqual_FloatFloat ( float A, float B );
    bool EqualEqual_FloatFloat ( float A, float B );
    bool GreaterEqual_FloatFloat ( float A, float B );
    bool LessEqual_FloatFloat ( float A, float B );
    bool Greater_FloatFloat ( float A, float B );
    bool Less_FloatFloat ( float A, float B );
    float Subtract_FloatFloat ( float A, float B );
    float Add_FloatFloat ( float A, float B );
    float Percent_FloatFloat ( float A, float B );
    float Divide_FloatFloat ( float A, float B );
    float Multiply_FloatFloat ( float A, float B );
    float MultiplyMultiply_FloatFloat ( float Base, float Exp );
    float Subtract_PreFloat ( float A );
    struct FString ToHex ( int A );
    int Clamp ( int V, int A, int B );
    int Max ( int A, int B );
    int Min ( int A, int B );
    int Rand ( int Max );
    int SubtractSubtract_Int ( int* A );
    int AddAdd_Int ( int* A );
    int SubtractSubtract_PreInt ( int* A );
    int AddAdd_PreInt ( int* A );
    int SubtractEqual_IntInt ( int B, int* A );
    int AddEqual_IntInt ( int B, int* A );
    int DivideEqual_IntFloat ( float B, int* A );
    int MultiplyEqual_IntFloat ( float B, int* A );
    int Or_IntInt ( int A, int B );
    int Xor_IntInt ( int A, int B );
    int And_IntInt ( int A, int B );
    bool NotEqual_IntInt ( int A, int B );
    bool EqualEqual_IntInt ( int A, int B );
    bool GreaterEqual_IntInt ( int A, int B );
    bool LessEqual_IntInt ( int A, int B );
    bool Greater_IntInt ( int A, int B );
    bool Less_IntInt ( int A, int B );
    int GreaterGreaterGreater_IntInt ( int A, int B );
    int GreaterGreater_IntInt ( int A, int B );
    int LessLess_IntInt ( int A, int B );
    int Subtract_IntInt ( int A, int B );
    int Add_IntInt ( int A, int B );
    int Percent_IntInt ( int A, int B );
    int Divide_IntInt ( int A, int B );
    int Multiply_IntInt ( int A, int B );
    int Subtract_PreInt ( int A );
    int Complement_PreInt ( int A );
    unsigned char SubtractSubtract_Byte ( unsigned char* A );
    unsigned char AddAdd_Byte ( unsigned char* A );
    unsigned char SubtractSubtract_PreByte ( unsigned char* A );
    unsigned char AddAdd_PreByte ( unsigned char* A );
    unsigned char SubtractEqual_ByteByte ( unsigned char B, unsigned char* A );
    unsigned char AddEqual_ByteByte ( unsigned char B, unsigned char* A );
    unsigned char DivideEqual_ByteByte ( unsigned char B, unsigned char* A );
    unsigned char MultiplyEqual_ByteFloat ( float B, unsigned char* A );
    unsigned char MultiplyEqual_ByteByte ( unsigned char B, unsigned char* A );
    bool OrOr_BoolBool ( unsigned long A, unsigned long B );
    bool XorXor_BoolBool ( unsigned long A, unsigned long B );
    bool AndAnd_BoolBool ( unsigned long A, unsigned long B );
    bool NotEqual_BoolBool ( unsigned long A, unsigned long B );
    bool EqualEqual_BoolBool ( unsigned long A, unsigned long B );
    bool Not_PreBool ( unsigned long A );

    // Virtual Functions
    virtual void VirtualFunction00 ( );                                                                            // 0x00D97A90 (0x00)
    virtual void VirtualFunction01 ( );                                                                            // 0x00462700 (0x04)
    virtual void VirtualFunction02 ( );                                                                            // 0x00460BE0 (0x08)
    virtual void VirtualFunction03 ( );                                                                            // 0x00BCF0D0 (0x0C)
    virtual void VirtualFunction04 ( );                                                                            // 0x00A3A830 (0x10)
    virtual void VirtualFunction05 ( );                                                                            // 0x006BED90 (0x14)
    virtual void VirtualFunction06 ( );                                                                            // 0x00497C10 (0x18)
    virtual void VirtualFunction07 ( );                                                                            // 0x00497C70 (0x1C)
    virtual void VirtualFunction08 ( );                                                                            // 0x0043D6A0 (0x20)
    virtual void VirtualFunction09 ( );                                                                            // 0x00499B90 (0x24)
    virtual void VirtualFunction10 ( );                                                                            // 0x00D97A90 (0x28)
    virtual void VirtualFunction11 ( );                                                                            // 0x00493EC0 (0x2C)
    virtual void VirtualFunction12 ( );                                                                            // 0x00457E20 (0x30)
    virtual void VirtualFunction13 ( );                                                                            // 0x0045F1C0 (0x34)
    virtual void VirtualFunction14 ( );                                                                            // 0x00493640 (0x38)
    virtual void VirtualFunction15 ( );                                                                            // 0x0042C1B0 (0x3C)
    virtual void VirtualFunction16 ( );                                                                            // 0x006BED90 (0x40)
    virtual void VirtualFunction17 ( );                                                                            // 0x00494840 (0x44)
    virtual void VirtualFunction18 ( );                                                                            // 0x004933D0 (0x48)
    virtual void VirtualFunction19 ( );                                                                            // 0x00497950 (0x4C)
    virtual void VirtualFunction20 ( );                                                                            // 0x00494910 (0x50)
    virtual void VirtualFunction21 ( );                                                                            // 0x004935A0 (0x54)
    virtual void VirtualFunction22 ( );                                                                            // 0x004933F0 (0x58)
    virtual void VirtualFunction23 ( );                                                                            // 0x004935D0 (0x5C)
    virtual void VirtualFunction24 ( );                                                                            // 0x006BED90 (0x60)
    virtual void VirtualFunction25 ( );                                                                            // 0x006BED90 (0x64)
    virtual void VirtualFunction26 ( );                                                                            // 0x004933E0 (0x68)
    virtual void VirtualFunction27 ( );                                                                            // 0x004933F0 (0x6C)
    virtual void VirtualFunction28 ( );                                                                            // 0x004935D0 (0x70)
    virtual void VirtualFunction29 ( );                                                                            // 0x004933F0 (0x74)
    virtual void VirtualFunction30 ( );                                                                            // 0x004935D0 (0x78)
    virtual void VirtualFunction31 ( );                                                                            // 0x00495E80 (0x7C)
    virtual void VirtualFunction32 ( );                                                                            // 0x00494A00 (0x80)
    virtual void VirtualFunction33 ( );                                                                            // 0x00494BB0 (0x84)
    virtual void VirtualFunction34 ( );                                                                            // 0x006BED90 (0x88)
    virtual void VirtualFunction35 ( );                                                                            // 0x00452E60 (0x8C)
    virtual void VirtualFunction36 ( );                                                                            // 0x004A0E10 (0x90)
    virtual void VirtualFunction37 ( );                                                                            // 0x00403E90 (0x94)
    virtual void VirtualFunction38 ( );                                                                            // 0x00403EC0 (0x98)
    virtual void VirtualFunction39 ( );                                                                            // 0x00403EF0 (0x9C)
    virtual void VirtualFunction40 ( );                                                                            // 0x00404DF0 (0xA0)
    virtual void VirtualFunction41 ( );                                                                            // 0x00CA8350 (0xA4)
    virtual void VirtualFunction42 ( );                                                                            // 0x00CE5C30 (0xA8)
    virtual void VirtualFunction43 ( );                                                                            // 0x00CE5C30 (0xAC)
    virtual void VirtualFunction44 ( );                                                                            // 0x006BED90 (0xB0)
    virtual void VirtualFunction45 ( );                                                                            // 0x00CA8350 (0xB4)
    virtual void VirtualFunction46 ( );                                                                            // 0x008E0B30 (0xB8)
    virtual void VirtualFunction47 ( );                                                                            // 0x008EB890 (0xBC)
    virtual void VirtualFunction48 ( );                                                                            // 0x00452EE0 (0xC0)
    virtual void VirtualFunction49 ( );                                                                            // 0x0045B500 (0xC4)
    virtual void VirtualFunction50 ( );                                                                            // 0x00A3A830 (0xC8)
    virtual void VirtualFunction51 ( );                                                                            // 0x00A3A830 (0xCC)
    virtual void VirtualFunction52 ( );                                                                            // 0x0043D590 (0xD0)
    virtual void VirtualFunction53 ( );                                                                            // 0x00460A90 (0xD4)
    virtual void VirtualFunction54 ( );                                                                            // 0x004957B0 (0xD8)
    virtual void VirtualFunction55 ( );                                                                            // 0x00B843A0 (0xDC)
    virtual void VirtualFunction56 ( );                                                                            // 0x00493580 (0xE0)
    virtual void VirtualFunction57 ( );                                                                            // 0x0042A720 (0xE4)
    virtual void VirtualFunction58 ( );                                                                            // 0x004A07D0 (0xE8)
    virtual void VirtualFunction59 ( );                                                                            // 0x00CA8350 (0xEC)
    virtual void VirtualFunction60 ( );                                                                            // 0x00401A50 (0xF0)
    virtual void VirtualFunction61 ( );                                                                            // 0x00401A70 (0xF4)
    virtual void VirtualFunction62 ( );                                                                            // 0x004A2470 (0xF8)
    virtual void VirtualFunction63 ( );                                                                            // 0x00493400 (0xFC)
    virtual void VirtualFunction64 ( );                                                                            // 0x0045DF30 (0x100)
    virtual void ProcessEvent ( class UFunction* pFunction, void* pParms, void* pResult = NULL );                // 0x00456F90 (0x104)
};

// Class Core.TextBuffer
// 0x0024 (0x0060 - 0x003C)
class UTextBuffer : public UObject
{
public:
    unsigned char                                      UnknownData00[ 0x24 ];                                    // 0x003C (0x0024) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 0 ];

        return pClassPointer;
    };

};

// Class Core.Subsystem
// 0x0004 (0x0040 - 0x003C)
class USubsystem : public UObject
{
public:
    struct FPointer                                    VfTable_FExec;                                            // 0x003C (0x0004) [0x0000000000801002]              ( CPF_Const | CPF_Native | CPF_NoExport )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 3 ];

        return pClassPointer;
    };

};

// Class Core.System
// 0x00BC (0x00FC - 0x0040)
class USystem : public USubsystem
{
public:
    int                                                StaleCacheDays;                                           // 0x0040 (0x0004) [0x0000000000004000]              ( CPF_Config )
    int                                                MaxStaleCacheSize;                                        // 0x0044 (0x0004) [0x0000000000004000]              ( CPF_Config )
    int                                                MaxOverallCacheSize;                                      // 0x0048 (0x0004) [0x0000000000004000]              ( CPF_Config )
    int                                                PackageSizeSoftLimit;                                     // 0x004C (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              AsyncIOBandwidthLimit;                                    // 0x0050 (0x0004) [0x0000000000004000]              ( CPF_Config )
    struct FString                                     SavePath;                                                 // 0x0054 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     CachePath;                                                // 0x0060 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     CacheExt;                                                 // 0x006C (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     ScreenShotPath;                                           // 0x0078 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< struct FString >                           Paths;                                                    // 0x0084 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< struct FString >                           SeekFreePCPaths;                                          // 0x0090 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< struct FString >                           ScriptPaths;                                              // 0x009C (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< struct FString >                           FRScriptPaths;                                            // 0x00A8 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< struct FString >                           CutdownPaths;                                             // 0x00B4 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< struct FName >                             Suppress;                                                 // 0x00C0 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< struct FString >                           Extensions;                                               // 0x00CC (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< struct FString >                           SeekFreePCExtensions;                                     // 0x00D8 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< struct FString >                           LocalizationPaths;                                        // 0x00E4 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     TextureFileCacheExtension;                                // 0x00F0 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 2 ];

        return pClassPointer;
    };

};

// Class Core.PackageMap
// 0x0084 (0x00C0 - 0x003C)
class UPackageMap : public UObject
{
public:
    unsigned char                                      UnknownData00[ 0x84 ];                                    // 0x003C (0x0084) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 4 ];

        return pClassPointer;
    };

};

// Class Core.ObjectSerializer
// 0x000C (0x0048 - 0x003C)
class UObjectSerializer : public UObject
{
public:
    unsigned char                                      UnknownData00[ 0xC ];                                     // 0x003C (0x000C) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 5 ];

        return pClassPointer;
    };

};

// Class Core.ObjectRedirector
// 0x0004 (0x0040 - 0x003C)
class UObjectRedirector : public UObject
{
public:
    unsigned char                                      UnknownData00[ 0x4 ];                                     // 0x003C (0x0004) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 6 ];

        return pClassPointer;
    };

};

// Class Core.MetaData
// 0x003C (0x0078 - 0x003C)
class UMetaData : public UObject
{
public:
    unsigned char                                      UnknownData00[ 0x3C ];                                    // 0x003C (0x003C) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 7 ];

        return pClassPointer;
    };

};

// Class Core.Linker
// 0x012C (0x0168 - 0x003C)
class ULinker : public UObject
{
public:
    unsigned char                                      UnknownData00[ 0x12C ];                                   // 0x003C (0x012C) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 9 ];

        return pClassPointer;
    };

};

// Class Core.LinkerSave
// 0x00A0 (0x0208 - 0x0168)
class ULinkerSave : public ULinker
{
public:
    unsigned char                                      UnknownData00[ 0xA0 ];                                    // 0x0168 (0x00A0) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 8 ];

        return pClassPointer;
    };

};

// Class Core.LinkerLoad
// 0x05BC (0x0724 - 0x0168)
class ULinkerLoad : public ULinker
{
public:
    unsigned char                                      UnknownData00[ 0x5BC ];                                   // 0x0168 (0x05BC) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 10 ];

        return pClassPointer;
    };

};

// Class Core.Interface
// 0x0000 (0x003C - 0x003C)
class UInterface : public UObject
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 11 ];

        return pClassPointer;
    };

};

// Class Core.Field
// 0x0004 (0x0040 - 0x003C)
class UField : public UObject
{
public:
    class UField*                                        Next;                                                     // NOT AUTO-GENERATED PROPERTY 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 14 ];

        return pClassPointer;
    };

};

// Class Core.Struct
// 0x0050 (0x0090 - 0x0040)
class UStruct : public UField
{
public:
    unsigned char                                        UnknownData00[0x8];                                        // NOT AUTO-GENERATED PROPERTY 
    class UField*                                        SuperField;                                                // NOT AUTO-GENERATED PROPERTY 
    class UField*                                        Children;                                                // NOT AUTO-GENERATED PROPERTY 
    unsigned long                                        PropertySize;                                            // NOT AUTO-GENERATED PROPERTY 
    unsigned char                                        UnknownData01[0x3C];                                    // NOT AUTO-GENERATED PROPERTY 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 13 ];

        return pClassPointer;
    };

};

// Class Core.ScriptStruct
// 0x001C (0x00AC - 0x0090)
class UScriptStruct : public UStruct
{
public:
    unsigned char                                      UnknownData00[ 0x1C ];                                    // 0x0090 (0x001C) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 12 ];

        return pClassPointer;
    };

};

// Class Core.Function
// 0x0020 (0x00B0 - 0x0090)
class UFunction : public UStruct
{
public:
    unsigned long                                        FunctionFlags;                                            // NOT AUTO-GENERATED PROPERTY 
    unsigned short                                        iNative;                                                // NOT AUTO-GENERATED PROPERTY 
    unsigned short                                        RepOffset;                                                // NOT AUTO-GENERATED PROPERTY 
    struct FName                                        FriendlyName;                                            // NOT AUTO-GENERATED PROPERTY 
    unsigned short                                        NumParms;                                                // NOT AUTO-GENERATED PROPERTY 
    unsigned short                                        ParmsSize;                                                // NOT AUTO-GENERATED PROPERTY 
    unsigned long                                        ReturnValueOffset;                                        // NOT AUTO-GENERATED PROPERTY 
    unsigned char                                        UnknownData00[0x04];                                    // NOT AUTO-GENERATED PROPERTY 
    void*                                                Func;                                                    // NOT AUTO-GENERATED PROPERTY 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 15 ];

        return pClassPointer;
    };

};

// Class Core.Property
// 0x0040 (0x0080 - 0x0040)
class UProperty : public UField
{
public:
    unsigned long         ArrayDim;               // 0x0040 (0x04)
    unsigned long         ElementSize;            // 0x0044 (0x04)
    FQWord                PropertyFlags;          // 0x0048 (0x08)
    unsigned long         PropertySize;           // 0x0050 (0x04)
    unsigned char         UnknownData00[0x0C];    // 0x0054 (0x0C)
    unsigned long         Offset;                 // 0x0060 (0x04)
    unsigned char         UnknownData01[0x1C];    // 0x0064 (0x1C)

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 17 ];

        return pClassPointer;
    };

};

// Class Core.StructProperty
// 0x0004 (0x0084 - 0x0080)
class UStructProperty : public UProperty
{
public:
    unsigned char                                      UnknownData00[ 0x4 ];                                     // 0x0080 (0x0004) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 16 ];

        return pClassPointer;
    };

};

// Class Core.StrProperty
// 0x0000 (0x0080 - 0x0080)
class UStrProperty : public UProperty
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 18 ];

        return pClassPointer;
    };

};

// Class Core.ObjectProperty
// 0x0004 (0x0084 - 0x0080)
class UObjectProperty : public UProperty
{
public:
    unsigned char                                      UnknownData00[ 0x4 ];                                     // 0x0080 (0x0004) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 20 ];

        return pClassPointer;
    };

};

// Class Core.ComponentProperty
// 0x0000 (0x0084 - 0x0084)
class UComponentProperty : public UObjectProperty
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 19 ];

        return pClassPointer;
    };

};

// Class Core.ClassProperty
// 0x0004 (0x0088 - 0x0084)
class UClassProperty : public UObjectProperty
{
public:
    unsigned char                                      UnknownData00[ 0x4 ];                                     // 0x0084 (0x0004) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 21 ];

        return pClassPointer;
    };

};

// Class Core.NameProperty
// 0x0000 (0x0080 - 0x0080)
class UNameProperty : public UProperty
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 22 ];

        return pClassPointer;
    };

};

// Class Core.MapProperty
// 0x0008 (0x0088 - 0x0080)
class UMapProperty : public UProperty
{
public:
    unsigned char                                      UnknownData00[ 0x8 ];                                     // 0x0080 (0x0008) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 23 ];

        return pClassPointer;
    };

};

// Class Core.IntProperty
// 0x0000 (0x0080 - 0x0080)
class UIntProperty : public UProperty
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 24 ];

        return pClassPointer;
    };

};

// Class Core.InterfaceProperty
// 0x0004 (0x0084 - 0x0080)
class UInterfaceProperty : public UProperty
{
public:
    unsigned char                                      UnknownData00[ 0x4 ];                                     // 0x0080 (0x0004) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 25 ];

        return pClassPointer;
    };

};

// Class Core.FloatProperty
// 0x0000 (0x0080 - 0x0080)
class UFloatProperty : public UProperty
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 26 ];

        return pClassPointer;
    };

};

// Class Core.DelegateProperty
// 0x0008 (0x0088 - 0x0080)
class UDelegateProperty : public UProperty
{
public:
    unsigned char                                      UnknownData00[ 0x8 ];                                     // 0x0080 (0x0008) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 27 ];

        return pClassPointer;
    };

};

// Class Core.ByteProperty
// 0x0004 (0x0084 - 0x0080)
class UByteProperty : public UProperty
{
public:
    unsigned char                                      UnknownData00[ 0x4 ];                                     // 0x0080 (0x0004) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 28 ];

        return pClassPointer;
    };

};

// Class Core.BoolProperty
// 0x0004 (0x0084 - 0x0080)
class UBoolProperty : public UProperty
{
public:
    unsigned long         BitMask;                // 0x0088 (0x04)

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 29 ];

        return pClassPointer;
    };

};

// Class Core.ArrayProperty
// 0x0004 (0x0084 - 0x0080)
class UArrayProperty : public UProperty
{
public:
    unsigned char                                      UnknownData00[ 0x4 ];                                     // 0x0080 (0x0004) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 30 ];

        return pClassPointer;
    };

};

// Class Core.Enum
// 0x000C (0x004C - 0x0040)
class UEnum : public UField
{
public:
    unsigned char                                      UnknownData00[ 0xC ];                                     // 0x0040 (0x000C) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 31 ];

        return pClassPointer;
    };

};

// Class Core.Const
// 0x000C (0x004C - 0x0040)
class UConst : public UField
{
public:
    unsigned char                                      UnknownData00[ 0xC ];                                     // 0x0040 (0x000C) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 32 ];

        return pClassPointer;
    };

};

// Class Core.Factory
// 0x0034 (0x0070 - 0x003C)
class UFactory : public UObject
{
public:
    class UClass*                                      SupportedClass;                                           // 0x003C (0x0004) [0x0000000000000000]              
    class UClass*                                      ContextClass;                                             // 0x0040 (0x0004) [0x0000000000000000]              
    struct FString                                     Description;                                              // 0x0044 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FString >                           Formats;                                                  // 0x0050 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned long                                      bCreateNew : 1;                                           // 0x005C (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bEditAfterNew : 1;                                        // 0x005C (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bEditorImport : 1;                                        // 0x005C (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bText : 1;                                                // 0x005C (0x0004) [0x0000000000000000] [0x00000008] 
    int                                                AutoPriority;                                             // 0x0060 (0x0004) [0x0000000000000000]              
    TArray< struct FString >                           ValidGameNames;                                           // 0x0064 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 34 ];

        return pClassPointer;
    };

};

// Class Core.TextBufferFactory
// 0x0000 (0x0070 - 0x0070)
class UTextBufferFactory : public UFactory
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 33 ];

        return pClassPointer;
    };

};

// Class Core.Exporter
// 0x0028 (0x0064 - 0x003C)
class UExporter : public UObject
{
public:
    unsigned char                                      UnknownData00[ 0x4 ];                                     // 0x003C (0x0004) MISSED OFFSET
    TArray< struct FString >                           FormatExtension;                                          // 0x0040 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FString >                           FormatDescription;                                        // 0x004C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned char                                      UnknownData01[ 0xC ];                                     // 0x0058 (0x000C) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 35 ];

        return pClassPointer;
    };

};

// Class Core.Component
// 0x000C (0x0048 - 0x003C)
class UComponent : public UObject
{
public:
    class UClass*                                      TemplateOwnerClass;                                       // 0x003C (0x0004) [0x0000000000001002]              ( CPF_Const | CPF_Native )
    struct FName                                       TemplateName;                                             // 0x0040 (0x0008) [0x0000000000001002]              ( CPF_Const | CPF_Native )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37 ];

        return pClassPointer;
    };

};

// Class Core.DistributionVector
// 0x0008 (0x0050 - 0x0048)
class UDistributionVector : public UComponent
{
public:
    struct FPointer                                    VfTable_FCurveEdInterface;                                // 0x0048 (0x0004) [0x0000000000801002]              ( CPF_Const | CPF_Native | CPF_NoExport )
    unsigned long                                      bCanBeBaked : 1;                                          // 0x004C (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bIsDirty : 1;                                             // 0x004C (0x0004) [0x0000000000000000] [0x00000002] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36 ];

        return pClassPointer;
    };

    struct FVector GetVectorValue ( float F, int LastExtreme );
};

// Class Core.DistributionFloat
// 0x0008 (0x0050 - 0x0048)
class UDistributionFloat : public UComponent
{
public:
    struct FPointer                                    VfTable_FCurveEdInterface;                                // 0x0048 (0x0004) [0x0000000000801002]              ( CPF_Const | CPF_Native | CPF_NoExport )
    unsigned long                                      bCanBeBaked : 1;                                          // 0x004C (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bIsDirty : 1;                                             // 0x004C (0x0004) [0x0000000000000000] [0x00000002] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38 ];

        return pClassPointer;
    };

    float GetFloatValue ( float F );
};

// Class Core.Commandlet
// 0x0040 (0x007C - 0x003C)
class UCommandlet : public UObject
{
public:
    struct FString                                     HelpDescription;                                          // 0x003C (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     HelpUsage;                                                // 0x0048 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     HelpWebLink;                                              // 0x0054 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    TArray< struct FString >                           HelpParamNames;                                           // 0x0060 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    TArray< struct FString >                           HelpParamDescriptions;                                    // 0x006C (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    unsigned long                                      IsServer : 1;                                             // 0x0078 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      IsClient : 1;                                             // 0x0078 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      IsEditor : 1;                                             // 0x0078 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      LogToConsole : 1;                                         // 0x0078 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      ShowErrorCount : 1;                                       // 0x0078 (0x0004) [0x0000000000000000] [0x00000010] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40 ];

        return pClassPointer;
    };

    int eventMain ( struct FString Params );
};

// Class Core.HelpCommandlet
// 0x0000 (0x007C - 0x007C)
class UHelpCommandlet : public UCommandlet
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39 ];

        return pClassPointer;
    };

    int eventMain ( struct FString Params );
};

// Class Core.State
// 0x0048 (0x00D8 - 0x0090)
class UState : public UStruct
{
public:
    unsigned char                                      UnknownData00[ 0x48 ];                                    // 0x0090 (0x0048) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 51 ];

        return pClassPointer;
    };

};

// Class Core.Package
// 0x00AC (0x00E8 - 0x003C)
class UPackage : public UObject
{
public:
    unsigned char                                      UnknownData00[ 0xAC ];                                    // 0x003C (0x00AC) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 52 ];

        return pClassPointer;
    };

};

// Class Core.Class
// 0x00FC (0x01D4 - 0x00D8)
class UClass : public UState
{
public:
    unsigned char                                        UnknownData00[0x88];                                    // NOT AUTO-GENERATED PROPERTY 
    UObject                                                *Default;                                                // NOT AUTO-GENERATED PROPERTY 
    unsigned char                                        UnknownData01[0x64];                                    // NOT AUTO-GENERATED PROPERTY 
    TArray<int>                                            UnknownTArray;                                            // NOT AUTO-GENERATED PROPERTY 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 53 ];

        return pClassPointer;
    };

};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif