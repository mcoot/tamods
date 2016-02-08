-- Disable most ambient sounds, including the wind blowing sound when going fast
modifySoundRe("(\\.AmbientSound|CreditsSound|IdleProjectile|Speed_1P)", 1.0, 0.0)

-- Make pistols sound a bit more powerfull
modifySoundRe("(NovaColt|Pistol)_3P_Fire", 0.8, 1.0)

-- Make shotguns sound a bit more powerfull
modifySoundRe("shotgun.*fire", 0.7, 1.2)

-- Disable the firing sounds of all chainguns
modifySoundRe("AUD_WEP_(AssaultRifle|SMG_NJ4|Falcon_Auto_Pistol|Chaingun|LMG)\\.(Spin|Fire)", 1.0, 0.0)

-- Mute all VGS taunts
modifySoundRe("taunt", 1.0, 0.0)