-- ==========================================
-- STEP 1: LOAD BYPASSES FIRST
-- ==========================================

-- BYPASS 1: Core Anti-Kick (Essential)
for k, v in pairs(getgc(true)) do
    if pcall(function()
        return rawget(v, "indexInstance")
    end) and type(rawget(v, "indexInstance")) == "table" and (rawget(v, "indexInstance"))[1] == "kick" then
        setreadonly(v, false)
        v.tvk = {
            "kick",
            function()
                return game.Workspace:WaitForChild("")
            end
        }
    end
end
task.wait(8)

-- BYPASS 2: Adonis Cries Anti-Kick (Optional)
task.spawn(function()
    pcall(function()
        loadstring(game:HttpGet("https://raw.githubusercontent.com/Pixeluted/adoniscries/main/Source.lua", true))()
    end)
end)
task.wait(5)

-- BYPASS 3: MEGGD Anti-Kick (Optional)
task.spawn(function()
    pcall(function()
        loadstring(game:HttpGet('https://raw.githubusercontent.com/SUUUUUS00000/MEGGD-Anti-kick/refs/heads/main/MEGGD%20Best%20Anti-kick.lua'))()
    end)
end)

-- ==========================================
-- STEP 2: WAIT 15 SECONDS
-- ==========================================
task.wait(15)

-- ==========================================
-- STEP 3: LOAD LIBRARY & CREATE MENU
-- ==========================================
local repo = "https://raw.githubusercontent.com/cloudsense-pub/UELinoriaLib/main/"
local Library = loadstring(game:HttpGet(repo .. "Library.lua"))()
local ThemeManager = loadstring(game:HttpGet(repo .. "addons/ThemeManager.lua"))()
local SaveManager = loadstring(game:HttpGet(repo .. "addons/SaveManager.lua"))()

Library.ShowToggleFrameInKeybinds = true
Library.ShowCustomCursor = true
Library.NotifySide = "Right" 

local Window = Library:CreateWindow({
    Title = "hooksenseㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ",
    Center = true, 
    AutoShow = true,
    Resizable = true,
    ShowCustomCursor = true,
    UnlockMouseWhileOpen = true,
    NotifySide = "Right", 
    TabPadding = 8,
    MenuFadeTime = 0.2
})

task.spawn(function()
    local MainFrame = Library.Main
    if MainFrame then
        local TabContainer = MainFrame:FindFirstChild("TabContainer") or MainFrame:FindFirstChildOfClass("Frame")
        if TabContainer then
            local ScrollFrame = Instance.new("ScrollingFrame")
            ScrollFrame.Name = "ScrollingTabContainer"
            ScrollFrame.Size = UDim2.new(1, -20, 0, 32)
            ScrollFrame.Position = UDim2.new(0, 10, 0, 38)
            ScrollFrame.BackgroundTransparency = 1
            ScrollFrame.BorderSizePixel = 0
            ScrollFrame.ScrollBarThickness = 2
            ScrollFrame.ScrollingDirection = Enum.ScrollingDirection.X
            ScrollFrame.CanvasSize = UDim2.new(0, 0, 0, 0)
            ScrollFrame.ClipsDescendants = true
            ScrollFrame.Parent = MainFrame

            local Layout = Instance.new("UIListLayout")
            Layout.FillDirection = Enum.FillDirection.Horizontal
            Layout.SortOrder = Enum.SortOrder.LayoutOrder
            Layout.Padding = UDim.new(0, 6)
            Layout.Parent = ScrollFrame

            for _, child in ipairs(TabContainer:GetChildren()) do
                if child:IsA("TextButton") or child:IsA("GuiButton") then
                    child.Parent = ScrollFrame
                end
            end
            TabContainer:Destroy()

            Layout:GetPropertyChangedSignal("AbsoluteContentSize"):Connect(function()
                ScrollFrame.CanvasSize = UDim2.new(0, Layout.AbsoluteContentSize.X + 15, 0, 0)
            end)
        end
    end
end)

-- LOCAL CONFIG VARIABLES
local SilentAimEnabled = false
local ResolverEnabled = false
local BulletTPEnabled = false
local WallCheckEnabled = false
local TeamCheckEnabled = false
local DieCheckEnabled = true
local LookAtEnabled = false
local FOVSize = 100
local FOVVisible = true
local TracerEnabled = true

local MobileAimbotEnabled = false
local AimbotSmoothness = 0.1
local AutoPredictionEnabled = false
local PredictionValue = 0.1
local AimbotTargetPart = "Head"

local JumpSmooth = 1
local SmoothX = 1
local SmoothZ = 1
local PermLockEnabled = false
local PermTargetList = {}
local GlobalFontSetting = Enum.Font.Cartoon

local CustomFOVValue = 70

local RobloxFontsList = {}
for _, font in ipairs(Enum.Font:GetEnumItems()) do
    table.insert(RobloxFontsList, font.Name)
end
table.sort(RobloxFontsList)

local HitSoundMode = "None"
local HitSoundVolume = 2
local SoundIDs = {
    ["None"] = "None",
    ["Spark"] = "rbxassetid://110241936966089",
    ["Neverlose"] = "rbxassetid://18391691942",
    ["Rust"] = "rbxassetid://138750331387064",
    ["Fatality"] = "rbxassetid://111508823459652",
    ["Fatality 2"] = "rbxassetid://17802817724",
    ["Minecraft xp"] = "rbxassetid://17148249625",
    ["Minecraft"] = "rbxassetid://135478009117226",
    ["Crack"] = "rbxassetid://126409451844008",
    ["Skeet"] = "rbxassetid://80461265049096"
}

local HitNotifyEnabled = false 
local HitNotifyDuration = 2.5
local HitNotifyTransparency = 0.0
local HitNotifyFont = Enum.Font.Cartoon
local HitNotifyTemplate = "Hit {name} in the {part} for {dmg} dmg with {weapon}" 
local HitNotifyPosX = 50 
local HitNotifyPosY = 65 

local HitOverlayEnabled = false
local HitOverlayColor = Color3.fromRGB(255, 0, 0)

local SkyboxEnabled = false
local SelectedSkybox = "Minecraft"
local SkyboxIDs = {
    ["Minecraft"] = "rbxassetid://96736589365838",
    ["Minecraft 2"] = "rbxassetid://117301665698887",
    ["Skyblox 1"] = "rbxassetid://4951222008",
    ["Skyblox 2"] = "rbxassetid://4604073339",
    ["Skyblox 3"] = "rbxassetid://8464073887",
    ["Skyblox 4"] = "rbxassetid://12300321824",
    ["Skyblox 5"] = "rbxassetid://90988519"
}

local FOVCircleColor = Color3.fromRGB(255, 255, 255)
local FOVCircleOutlineColor = Color3.fromRGB(0, 0, 0)
local TracerLineColor = Color3.fromRGB(255, 0, 0)
local TracerLineOutlineColor = Color3.fromRGB(0, 0, 0)
local TracerThickness = 1.0
local TracerOutlineThickness = 3.0

local FOVFillEnabled = false
local FOVFillTransparency = 0.2
local FOVFillColor1 = Color3.fromRGB(255, 0, 0)
local FOVFillColor2 = Color3.fromRGB(0, 255, 0)
local FOVFillColor3 = Color3.fromRGB(0, 0, 255)
local FOVFillRotateEnabled = false
local FOVFillRotateSpeed = 1
local currentRotationAngle = 0

local TargetPartMode = "Head"
local TransitionSpeed = 5
local MaxTargetDistance = 10000

local AntiAimEnabled = false
local AntiAimMode = "Spin"
local AntiAimSpeed = 15
local JitterMode = "Multi"

local ThirdPersonEnabled = false
local ThirdPersonDistance = 12
local MotionBlurEnabled = false
local MotionBlurIntensity = 1.5

local BhopEnabled = false
local BhopSpeedMultiplier = 1.5

local TargetHudToggle = true
local TargetHudPosX = 0
local TargetHudPosY = 0
local TargetHudBorderColor1 = Color3.fromRGB(0, 255, 100)
local TargetHudBorderColor2 = Color3.fromRGB(0, 150, 0)
local TargetHudHealthHigh = Color3.fromRGB(0, 255, 100)
local TargetHudHealthMid = Color3.fromRGB(255, 200, 0)
local TargetHudHealthLow = Color3.fromRGB(255, 50, 50)

local AtmosphereEnabled = false 
local AtmosphereColor = Color3.fromRGB(178, 200, 255)
local AtmosphereDecay = Color3.fromRGB(255, 178, 120)
local AtmosphereGlare = 0.4
local AtmosphereHaze = 1.2
local AtmosphereOffset = 0.25
local AtmosphereDensity = 0.35

local Camera = workspace.CurrentCamera
local Players = game.Players
local LocalPlayer = Players.LocalPlayer
local CoreGui = game:GetService("CoreGui")
local UserInputService = game:GetService("UserInputService")
local SoundService = game:GetService("SoundService")
local Lighting = game:GetService("Lighting")
local TweenService = game:GetService("TweenService")
local DisplayNameLabel, UsernameLabel, UserIdLabel, AvatarImage
local TargetVelocityHistory = {}

local TargetGuiParent = LocalPlayer:WaitForChild("PlayerGui", 5) or (CoreGui:FindFirstChild("RobloxGui") or CoreGui)

local HitOverlayGui = Instance.new("ScreenGui")
HitOverlayGui.Name = "hooksense_HitOverlayGui"
HitOverlayGui.ResetOnSpawn = false
HitOverlayGui.IgnoreGuiInset = true
HitOverlayGui.DisplayOrder = 99999
HitOverlayGui.Parent = TargetGuiParent

local OverlayFrame = Instance.new("Frame")
OverlayFrame.Name = "HitOverlay"
OverlayFrame.Size = UDim2.new(1, 0, 1, 0)
OverlayFrame.BorderSizePixel = 0
OverlayFrame.BackgroundColor3 = HitOverlayColor
OverlayFrame.BackgroundTransparency = 1
OverlayFrame.ZIndex = 99999
OverlayFrame.Parent = HitOverlayGui

local function TriggerHitOverlay()
    if not HitOverlayEnabled then return end
    OverlayFrame.BackgroundColor3 = HitOverlayColor
    
    local fadeIn = TweenService:Create(OverlayFrame, TweenInfo.new(0.05, Enum.EasingStyle.Quad, Enum.EasingDirection.Out), {BackgroundTransparency = 0.5})
    local fadeOut = TweenService:Create(OverlayFrame, TweenInfo.new(0.3, Enum.EasingStyle.Quad, Enum.EasingDirection.In), {BackgroundTransparency = 1})
    
    fadeIn:Play()
    fadeIn.Completed:Connect(function()
        task.wait(0.01)
        fadeOut:Play()
    end)
end

local CenterNotifyGui = Instance.new("ScreenGui")
CenterNotifyGui.Name = "hooksense_CenterNotifyGui"
CenterNotifyGui.ResetOnSpawn = false
CenterNotifyGui.Parent = TargetGuiParent

local CenterNotifyContainer = Instance.new("Frame")
CenterNotifyContainer.Name = "NotifyContainer"
CenterNotifyContainer.Size = UDim2.new(0.6, 0, 0.4, 0)
CenterNotifyContainer.AnchorPoint = Vector2.new(0.5, 0.5)
CenterNotifyContainer.Position = UDim2.new(HitNotifyPosX / 100, 0, HitNotifyPosY / 100, 0)
CenterNotifyContainer.BackgroundTransparency = 1
CenterNotifyContainer.BorderSizePixel = 0
CenterNotifyContainer.Parent = CenterNotifyGui

local CenterNotifyLayout = Instance.new("UIListLayout")
CenterNotifyLayout.FillDirection = Enum.FillDirection.Vertical
CenterNotifyLayout.HorizontalAlignment = Enum.HorizontalAlignment.Center
CenterNotifyLayout.VerticalAlignment = Enum.VerticalAlignment.Bottom
CenterNotifyLayout.SortOrder = Enum.SortOrder.LayoutOrder
CenterNotifyLayout.Padding = UDim.new(0, 5)
CenterNotifyLayout.Parent = CenterNotifyContainer

local function ShowCustomHitNotification(targetName, partName, damage, weaponName)
    if not HitNotifyEnabled then return end
    
    weaponName = weaponName or "Hands"
    
    local notifyText = HitNotifyTemplate
    notifyText = string.gsub(notifyText, "{name}", targetName)
    notifyText = string.gsub(notifyText, "{part}", partName)
    notifyText = string.gsub(notifyText, "{dmg}", tostring(damage))
    notifyText = string.gsub(notifyText, "{weapon}", weaponName)
    
    local NotifyLabel = Instance.new("TextLabel")
    NotifyLabel.Size = UDim2.new(1, 0, 0, 24)
    NotifyLabel.BackgroundTransparency = 1
    NotifyLabel.Text = notifyText
    NotifyLabel.TextColor3 = Color3.fromRGB(255, 255, 255)
    NotifyLabel.TextSize = 16
    NotifyLabel.Font = HitNotifyFont
    NotifyLabel.TextStrokeColor3 = Color3.fromRGB(0, 0, 0)
    
    NotifyLabel.Position = UDim2.new(0, 0, 0, 15)
    NotifyLabel.TextTransparency = 1
    NotifyLabel.TextStrokeTransparency = 1
    NotifyLabel.Parent = CenterNotifyContainer

    local openTween = TweenService:Create(NotifyLabel, TweenInfo.new(0.35, Enum.EasingStyle.Back, Enum.EasingDirection.Out), {
        Position = UDim2.new(0, 0, 0, 0),
        TextTransparency = HitNotifyTransparency,
        TextStrokeTransparency = math.clamp(HitNotifyTransparency + 0.4, 0, 1)
    })
    openTween:Play()

    task.delay(HitNotifyDuration, function()
        if not NotifyLabel or not NotifyLabel.Parent then return end
        
        local closeTween = TweenService:Create(NotifyLabel, TweenInfo.new(0.4, Enum.EasingStyle.Quad, Enum.EasingDirection.In), {
            Position = UDim2.new(0, 0, 0, 25),
            TextTransparency = 1,
            TextStrokeTransparency = 1
        })
        closeTween:Play()
        closeTween.Completed:Connect(function()
            NotifyLabel:Destroy()
        end)
    end)
end

local function PlayHitSound()
    if HitSoundMode == "None" or not SoundIDs[HitSoundMode] then return end
    local Sound = Instance.new("Sound")
    Sound.SoundId = SoundIDs[HitSoundMode]
    Sound.Volume = HitSoundVolume
    Sound.PlayOnRemove = true
    Sound.Parent = SoundService
    Sound:Destroy()
end

local function UpdateSkybox()
    for _, obj in ipairs(Lighting:GetChildren()) do
        if obj:IsA("Sky") and (obj.Name == "hooksenseSky" or obj.Name == "Sky") then
            obj:Destroy()
        end
    end
    if SkyboxEnabled and SkyboxIDs[SelectedSkybox] then
        local assetId = SkyboxIDs[SelectedSkybox]
        local success, result = pcall(function() return game:GetObjects(assetId)[1] end)
        if success and result and result:IsA("Sky") then
            local NewSky = result:Clone()
            NewSky.Name = "hooksenseSky"
            NewSky.Parent = Lighting
        else
            local NewSky = Instance.new("Sky")
            NewSky.Name = "hooksenseSky"
            NewSky.SkyboxBk = assetId
            NewSky.SkyboxDn = assetId
            NewSky.SkyboxFt = assetId
            NewSky.SkyboxLf = assetId
            NewSky.SkyboxRt = assetId
            NewSky.SkyboxUp = assetId
            NewSky.Parent = Lighting
        end
    end
end

local function UpdateAtmosphere()
    local atmos = Lighting:FindFirstChildOfClass("Atmosphere")
    if AtmosphereEnabled then
        if not atmos then
            atmos = Instance.new("Atmosphere")
            atmos.Parent = Lighting
        end
        atmos.Color = AtmosphereColor
        atmos.Decay = AtmosphereDecay
        atmos.Glare = AtmosphereGlare
        atmos.Haze = AtmosphereHaze
        atmos.Offset = AtmosphereOffset
        atmos.Density = AtmosphereDensity
        
        if not Lighting:FindFirstChildOfClass("Sky") then
            local DefaultSky = Instance.new("Sky")
            DefaultSky.Name = "hooksenseDefaultSky"
            DefaultSky.Parent = Lighting
        end
    else
        if atmos then
            atmos:Destroy()
        end
        if not SkyboxEnabled then
            local defaultSky = Lighting:FindFirstChild("hooksenseDefaultSky")
            if defaultSky then
                defaultSky:Destroy()
            end
        end
    end
end

UpdateAtmosphere()

local TargetGui = Instance.new("ScreenGui")
TargetGui.Name = "hooksenseTargetHudGui"
TargetGui.ResetOnSpawn = false
TargetGui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling
TargetGui.Parent = TargetGuiParent

local MainCanvas = Instance.new("CanvasGroup")
MainCanvas.Name = "MainTargetHUD"
MainCanvas.Size = UDim2.new(0, 280, 0, 90)
MainCanvas.AnchorPoint = Vector2.new(1, 0)
MainCanvas.Position = UDim2.new(1, -20, 0, 20)
MainCanvas.BackgroundColor3 = Color3.fromRGB(0, 0, 0)
MainCanvas.BackgroundTransparency = 0.15 
MainCanvas.GroupTransparency = 1 
MainCanvas.Visible = false
MainCanvas.Parent = TargetGui

local Corner = Instance.new("UICorner")
Corner.CornerRadius = UDim.new(0, 10)
Corner.Parent = MainCanvas

local Stroke = Instance.new("UIStroke")
Stroke.Color = Color3.fromRGB(255, 255, 255)
Stroke.Thickness = 1.8
Stroke.ApplyStrokeMode = Enum.ApplyStrokeMode.Border
Stroke.Parent = MainCanvas

local BorderGradient = Instance.new("UIGradient")
BorderGradient.Color = ColorSequence.new({
    ColorSequenceKeypoint.new(0, TargetHudBorderColor1),
    ColorSequenceKeypoint.new(1, TargetHudBorderColor2)
})
BorderGradient.Rotation = 45
BorderGradient.Parent = Stroke

local AvatarFrame = Instance.new("Frame")
AvatarFrame.Size = UDim2.new(0, 56, 0, 56)
AvatarFrame.Position = UDim2.new(0, 14, 0, 14)
AvatarFrame.BackgroundColor3 = Color3.fromRGB(15, 15, 22)
AvatarFrame.BorderSizePixel = 0
AvatarFrame.Parent = MainCanvas

local AvatarCorner = Instance.new("UICorner")
AvatarCorner.CornerRadius = UDim.new(1, 0) 
AvatarCorner.Parent = AvatarFrame

local AvatarStroke = Instance.new("UIStroke")
AvatarStroke.Color = Color3.fromRGB(0, 0, 0)
AvatarStroke.Thickness = 1.5
AvatarStroke.Parent = AvatarFrame

AvatarImage = Instance.new("ImageLabel")
AvatarImage.Size = UDim2.new(1, -4, 1, -4)
AvatarImage.Position = UDim2.new(0, 2, 0, 2)
AvatarImage.BackgroundTransparency = 1
AvatarImage.Parent = AvatarFrame

local ImgCorner = Instance.new("UICorner")
ImgCorner.CornerRadius = UDim.new(1, 0)
ImgCorner.Parent = AvatarImage

local InfoFrame = Instance.new("Frame")
InfoFrame.Size = UDim2.new(1, -95, 1, -40)
InfoFrame.Position = UDim2.new(0, 84, 0, 12)
InfoFrame.BackgroundTransparency = 1
InfoFrame.Parent = MainCanvas

DisplayNameLabel = Instance.new("TextLabel")
DisplayNameLabel.Size = UDim2.new(1, 0, 0, 18)
DisplayNameLabel.Font = GlobalFontSetting
DisplayNameLabel.TextSize = 14
DisplayNameLabel.TextColor3 = Color3.fromRGB(255, 255, 255)
DisplayNameLabel.TextXAlignment = Enum.TextXAlignment.Left
DisplayNameLabel.Text = "No Target"
DisplayNameLabel.BackgroundTransparency = 1
DisplayNameLabel.Parent = InfoFrame

UsernameLabel = Instance.new("TextLabel")
UsernameLabel.Size = UDim2.new(1, 0, 0, 14)
UsernameLabel.Position = UDim2.new(0, 0, 0, 18)
UsernameLabel.Font = GlobalFontSetting
UsernameLabel.TextSize = 11
UsernameLabel.TextColor3 = Color3.fromRGB(140, 140, 155)
UsernameLabel.TextXAlignment = Enum.TextXAlignment.Left
UsernameLabel.Text = "@none"
UsernameLabel.BackgroundTransparency = 1
UsernameLabel.Parent = InfoFrame

UserIdLabel = Instance.new("TextLabel")
UserIdLabel.Size = UDim2.new(1, 0, 0, 12)
UserIdLabel.Position = UDim2.new(0, 0, 0, 32)
UserIdLabel.Font = GlobalFontSetting
UserIdLabel.TextSize = 10
UserIdLabel.TextColor3 = Color3.fromRGB(255, 255, 255)
UserIdLabel.TextXAlignment = Enum.TextXAlignment.Left
UserIdLabel.Text = "USER ID: --"
UserIdLabel.BackgroundTransparency = 1
UserIdLabel.Parent = InfoFrame

local HealthBackground = Instance.new("Frame")
HealthBackground.Size = UDim2.new(1, -28, 0, 5)
HealthBackground.Position = UDim2.new(0, 14, 1, -16)
HealthBackground.BackgroundColor3 = Color3.fromRGB(20, 25, 20)
HealthBackground.BorderSizePixel = 0
HealthBackground.Parent = MainCanvas

local HealthBarCorner = Instance.new("UICorner")
HealthBarCorner.CornerRadius = UDim.new(0, 4)
HealthBarCorner.Parent = HealthBackground

local HealthBar = Instance.new("Frame")
HealthBar.Size = UDim2.new(1, 0, 1, 0)
HealthBar.BackgroundColor3 = TargetHudHealthHigh
HealthBar.BorderSizePixel = 0
HealthBar.Parent = HealthBackground

local MainBarCorner = Instance.new("UICorner")
MainBarCorner.CornerRadius = UDim.new(0, 4)
MainBarCorner.Parent = HealthBar

local isHudVisible = false
local function ToggleHUD(state)
    if state and TargetHudToggle then
        if not isHudVisible then
            isHudVisible = true
            MainCanvas.Visible = true
            TweenService:Create(MainCanvas, TweenInfo.new(0.2, Enum.EasingStyle.Cubic, Enum.EasingDirection.Out), {GroupTransparency = 0}):Play()
        end
    else
        if isHudVisible then
            isHudVisible = false
            local fadeOut = TweenService:Create(MainCanvas, TweenInfo.new(0.2, Enum.EasingStyle.Cubic, Enum.EasingDirection.In), {GroupTransparency = 1})
            fadeOut:Play()
            fadeOut.Completed:Connect(function()
                if not isHudVisible then MainCanvas.Visible = false end
            end)
        end
    end
end

local DeltaGradientGui = Instance.new("ScreenGui")
DeltaGradientGui.Name = "hooksense_DeltaGradientGui"
DeltaGradientGui.ResetOnSpawn = false
DeltaGradientGui.IgnoreGuiInset = true
DeltaGradientGui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling
DeltaGradientGui.Parent = TargetGuiParent

local FOVFillFrame = Instance.new("Frame")
FOVFillFrame.Name = "FOVGradientFrame"
FOVFillFrame.AnchorPoint = Vector2.new(0.5, 0.5)
FOVFillFrame.BorderSizePixel = 0
FOVFillFrame.BackgroundTransparency = 1
FOVFillFrame.Visible = false
FOVFillFrame.Parent = DeltaGradientGui

local FOVFillCorner = Instance.new("UICorner")
FOVFillCorner.CornerRadius = UDim.new(1, 0)
FOVFillCorner.Parent = FOVFillFrame

local FOVFillGradient = Instance.new("UIGradient")
FOVFillGradient.Parent = FOVFillFrame

-- [External-like Premium FOV Draw]
local FOVCircleOutline = Drawing.new("Circle")
FOVCircleOutline.Thickness = 2.0
FOVCircleOutline.NumSides = 144
FOVCircleOutline.Filled = false
FOVCircleOutline.Visible = FOVVisible

local FOVCircle = Drawing.new("Circle")
FOVCircle.Thickness = 1.0
FOVCircle.NumSides = 144
FOVCircle.Filled = false
FOVCircle.Visible = FOVVisible

local TracerLineOutline = Drawing.new("Line")
TracerLineOutline.Thickness = 3.0
TracerLineOutline.Transparency = 1.0

local TracerLine = Drawing.new("Line")
TracerLine.Thickness = 1.0
TracerLine.Transparency = 0.8

local function getScreenCenter()
    return Vector2.new(Camera.ViewportSize.X / 2, Camera.ViewportSize.Y / 2)
end

local function isBehindWall(targetPart)
    if not WallCheckEnabled then return false end
    local Parts = Camera:GetPartsObscuringTarget({targetPart.Position}, {LocalPlayer.Character, targetPart.Parent})
    return #Parts > 0
end

local function isDead(humanoid, char)
    if not DieCheckEnabled then return false end
    if humanoid and humanoid.Health <= 0 then return true end
    if char and not char:IsDescendantOf(workspace) then return true end
    return false
end

local CurrentAimTargetPosition = nil
local CurrentTargetPlayer = nil
local CurrentTargetCharacter = nil
local lastTarget = nil
local interpolationProgress = 0

task.spawn(function()
    while task.wait(0.01) do
        -- Track True Velocity for Resolver Logic
        for _, p in ipairs(Players:GetPlayers()) do
            if p.Character and p.Character:FindFirstChild("HumanoidRootPart") then
                local hrp = p.Character.HumanoidRootPart
                local hist = TargetVelocityHistory[p.Name]
                local currentTick = tick()
                if not hist then
                    TargetVelocityHistory[p.Name] = {Pos = hrp.Position, Time = currentTick, Velocity = Vector3.new(0, 0, 0)}
                else
                    local dt = currentTick - hist.Time
                    if dt > 0.005 then
                        local calculatedVel = (hrp.Position - hist.Pos) / dt
                        hist.Velocity = calculatedVel
                        hist.Pos = hrp.Position
                        hist.Time = currentTick
                    end
                end
            end
        end

        if not SilentAimEnabled and not MobileAimbotEnabled then
            CurrentAimTargetPosition = nil
            CurrentTargetPlayer = nil
            CurrentTargetCharacter = nil
            lastTarget = nil
            interpolationProgress = 0
        else
            local TempTargetChar = nil
            local TempPlayer = nil
            local MaxDistance = FOVSize
            local Center = getScreenCenter()
            local MyRoot = LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart")
            local PotentialTargets = {}

            if PermLockEnabled and #PermTargetList > 0 then
                for _, pName in ipairs(PermTargetList) do
                    local targetPlayerObject = Players:FindFirstChild(pName)
                    if targetPlayerObject and targetPlayerObject.Character then
                        local char = targetPlayerObject.Character
                        local rootPart = char:FindFirstChild("HumanoidRootPart")
                        local humanoid = char:FindFirstChildOfClass("Humanoid")
                        if rootPart and humanoid and not isDead(humanoid, char) then
                            if MyRoot and (rootPart.Position - MyRoot.Position).Magnitude <= MaxTargetDistance then
                                if not isBehindWall(rootPart) then
                                    if not (TeamCheckEnabled and targetPlayerObject.Team == LocalPlayer.Team) then
                                        TempTargetChar = char
                                        TempPlayer = targetPlayerObject
                                        break
                                    end
                                end
                            end
                        end
                    end
                end
            end

            if not TempTargetChar then
                for _, player in ipairs(Players:GetPlayers()) do
                    if player ~= LocalPlayer and player.Character then
                        table.insert(PotentialTargets, player.Character)
                    end
                end
                for _, char in ipairs(PotentialTargets) do
                    local rootPart = char:FindFirstChild("HumanoidRootPart")
                    local humanoid = char:FindFirstChildOfClass("Humanoid")
                    if rootPart and humanoid then
                        if isDead(humanoid, char) then continue end
                        if MyRoot and (rootPart.Position - MyRoot.Position).Magnitude > MaxTargetDistance then continue end
                        if isBehindWall(rootPart) then continue end
                        local targetPlayerObject = Players:GetPlayerFromCharacter(char)
                        if TeamCheckEnabled and targetPlayerObject and targetPlayerObject.Team == LocalPlayer.Team then continue end
                        local ScreenPosition, OnScreen = Camera:WorldToViewportPoint(rootPart.Position)
                        if OnScreen then
                            local DistanceToCenter = (Vector2.new(ScreenPosition.X, ScreenPosition.Y) - Center).Magnitude
                            if DistanceToCenter < MaxDistance then
                                TempTargetChar = char
                                TempPlayer = targetPlayerObject
                                MaxDistance = DistanceToCenter
                            end
                        end
                    end
                end
            end

            CurrentTargetPlayer = TempPlayer
            CurrentTargetCharacter = TempTargetChar

            if TempTargetChar then
                local targetPartName = MobileAimbotEnabled and AimbotTargetPart or TargetPartMode
                local head = TempTargetChar:FindFirstChild("Head")
                local root = TempTargetChar:FindFirstChild("HumanoidRootPart")
                
                local targetPartObj = nil
                if targetPartName == "Closet" then
                    local closestPart = nil
                    local minPartDist = math.huge
                    for _, part in ipairs(TempTargetChar:GetChildren()) do
                        if part:IsA("BasePart") then
                            local screenPos, onScreen = Camera:WorldToViewportPoint(part.Position)
                            if onScreen then
                                local dist = (Vector2.new(screenPos.X, screenPos.Y) - Center).Magnitude
                                if dist < minPartDist then
                                    minPartDist = dist
                                    closestPart = part
                                end
                            end
                        end
                    end
                    targetPartObj = closestPart or head or root
                else
                    targetPartObj = TempTargetChar:FindFirstChild(targetPartName) or head or root
                end

                if targetPartObj then
                    local basePosition = targetPartObj.Position
                    if AutoPredictionEnabled and root then
                        local ping = LocalPlayer:GetNetworkPing()
                        local targetedVelocity = root.Velocity

                        if ResolverEnabled then
                            local isVelocitySpoofed = (targetedVelocity.Magnitude > 75) or 
                                                      (math.abs(targetedVelocity.Y) > 50) or 
                                                      (targetedVelocity.Magnitude < 0.1 and root.AssemblyLinearVelocity.Magnitude > 10) or
                                                      (targetedVelocity.X ~= targetedVelocity.X)
                            
                            if isVelocitySpoofed then
                                local historyData = TargetVelocityHistory[TempPlayer and TempPlayer.Name or ""]
                                if historyData and historyData.Velocity.Magnitude < 150 then
                                    targetedVelocity = historyData.Velocity
                                else
                                    targetedVelocity = Vector3.new(0, 0, 0)
                                end
                            end
                        end

                        basePosition = basePosition + (targetedVelocity * ping * PredictionValue)
                    end
                    if TargetPartMode == "Root to Head" and not MobileAimbotEnabled then
                        if lastTarget ~= TempTargetChar then
                            lastTarget = TempTargetChar
                            interpolationProgress = 0
                        end
                        interpolationProgress = math.clamp(interpolationProgress + (0.01 * TransitionSpeed), 0, 1)
                        CurrentAimTargetPosition = root.Position:Lerp(head.Position, interpolationProgress)
                    else
                        CurrentAimTargetPosition = basePosition
                        lastTarget = TempTargetChar
                    end
                else
                    CurrentAimTargetPosition = nil
                end
            else
                lastTarget = nil
                interpolationProgress = 0
                CurrentAimTargetPosition = nil
            end
        end
    end
end)

local CurrentConnectedHumanoid = nil
local HealthConnection = nil
local function BindHealthTracker(targetPlayer)
    if not targetPlayer or not targetPlayer.Character then return end
    local hum = targetPlayer.Character:FindFirstChildOfClass("Humanoid")
    if not hum then return end
    if CurrentConnectedHumanoid == hum then return end
    if HealthConnection then HealthConnection:Disconnect() end
    CurrentConnectedHumanoid = hum
    local lastHealth = hum.Health
    HealthConnection = hum:GetPropertyChangedSignal("Health"):Connect(function()
        if CurrentTargetPlayer == targetPlayer and hum.Health < lastHealth then
            local damageCalculated = math.floor(lastHealth - hum.Health)
            task.spawn(PlayHitSound)
            task.spawn(TriggerHitOverlay) 
            local hitPartName = TargetPartMode
            if hitPartName == "Root to Head" then
                hitPartName = "Body/Head"
            elseif hitPartName == "HumanoidRootPart" then
                hitPartName = "Torso"
            end
            
            local weaponName = "Hands"
            if LocalPlayer.Character then
                local heldTool = LocalPlayer.Character:FindFirstChildOfClass("Tool")
                if heldTool then
                    weaponName = heldTool.Name
                end
            end
            
            task.spawn(ShowCustomHitNotification, targetPlayer.Name, hitPartName, damageCalculated, weaponName)
        end
        lastHealth = hum.Health
    end)
end

local function ResetCamera()
    Camera.CameraType = Enum.CameraType.Custom
    local char = LocalPlayer.Character
    local hum = char and char:FindFirstChildOfClass("Humanoid")
    if hum then
        hum.CameraOffset = Vector3.new(0, 0, 0)
    end
    LocalPlayer.CameraMaxZoomDistance = 128
    LocalPlayer.CameraMinZoomDistance = 0.5
end

local RunService = game:GetService("RunService")
local spinAngle = 0
local jitterToggle = false
local LastLoggedHudTargetId = 0
local currentHudHealthLerp = 0 
local LastCameraRotation = Camera.CFrame.LookVector

RunService.RenderStepped:Connect(function()
    local Center = getScreenCenter()
    local ShowCircle = FOVVisible and (SilentAimEnabled or MobileAimbotEnabled)
    
    FOVCircleOutline.Position = Center
    FOVCircleOutline.Radius = FOVSize
    FOVCircleOutline.Visible = ShowCircle
    FOVCircleOutline.Color = FOVCircleOutlineColor

    FOVCircle.Position = Center
    FOVCircle.Radius = FOVSize
    FOVCircle.Visible = ShowCircle
    FOVCircle.Color = FOVCircleColor

    if ShowCircle and FOVFillEnabled then
        FOVFillFrame.Position = UDim2.new(0, Center.X, 0, Center.Y)
        FOVFillFrame.Size = UDim2.new(0, FOVSize * 2, 0, FOVSize * 2)
        
        FOVFillGradient.Color = ColorSequence.new({
            ColorSequenceKeypoint.new(0, FOVFillColor1),
            ColorSequenceKeypoint.new(0.5, FOVFillColor2),
            ColorSequenceKeypoint.new(1, FOVFillColor3)
        })
        
        FOVFillFrame.BackgroundTransparency = FOVFillTransparency
        
        if FOVFillRotateEnabled then
            currentRotationAngle = (currentRotationAngle + (0.5 * FOVFillRotateSpeed)) % 360
        end
        FOVFillGradient.Rotation = currentRotationAngle
        FOVFillFrame.Visible = true
    else
        FOVFillFrame.Visible = false
    end

    if (SilentAimEnabled or MobileAimbotEnabled) and TracerEnabled and CurrentAimTargetPosition then
        local TargetPos, OnScreen = Camera:WorldToViewportPoint(CurrentAimTargetPosition)
        if OnScreen then
            local ToPos = Vector2.new(TargetPos.X, TargetPos.Y)
            TracerLineOutline.From = Center
            TracerLineOutline.To = ToPos
            TracerLineOutline.Visible = true
            TracerLineOutline.Color = TracerLineOutlineColor
            TracerLineOutline.Thickness = TracerOutlineThickness

            TracerLine.From = Center
            TracerLine.To = ToPos
            TracerLine.Visible = true
            TracerLine.Color = TracerLineColor
            TracerLine.Thickness = TracerThickness
        else
            TracerLineOutline.Visible = false
            TracerLine.Visible = false
        end
    else
        TracerLineOutline.Visible = false
        TracerLine.Visible = false
    end

    if MobileAimbotEnabled and CurrentAimTargetPosition then
        local targetCFrame = CFrame.new(Camera.CFrame.Position, CurrentAimTargetPosition)
        Camera.CFrame = Camera.CFrame:Lerp(targetCFrame, AimbotSmoothness)
    end

    MainCanvas.Position = UDim2.new(1, -20 + TargetHudPosX, 0, 20 + TargetHudPosY)

    if (SilentAimEnabled or MobileAimbotEnabled) and CurrentTargetPlayer and CurrentTargetPlayer.Character and TargetHudToggle then
        local Hum = CurrentTargetPlayer.Character:FindFirstChildOfClass("Humanoid")
        if Hum then
            DisplayNameLabel.Text = CurrentTargetPlayer.DisplayName
            UsernameLabel.Text = "@" .. CurrentTargetPlayer.Name
            UserIdLabel.Text = "USER ID: " .. tostring(CurrentTargetPlayer.UserId)
            
            local pct = math.clamp(Hum.Health / Hum.MaxHealth, 0, 1)
            
            if CurrentTargetPlayer.UserId ~= LastLoggedHudTargetId then
                currentHudHealthLerp = pct
                LastLoggedHudTargetId = CurrentTargetPlayer.UserId
                AvatarImage.Image = "rbxthumb://type=AvatarHeadShot&id=" .. tostring(CurrentTargetPlayer.UserId) .. "&w=150&h=150"
            end
            
            currentHudHealthLerp = currentHudHealthLerp + (pct - currentHudHealthLerp) * 0.12
            HealthBar.Size = UDim2.new(currentHudHealthLerp, 0, 1, 0)
            
            if currentHudHealthLerp > 0.6 then
                HealthBar.BackgroundColor3 = TargetHudHealthHigh
            elseif currentHudHealthLerp > 0.3 then
                HealthBar.BackgroundColor3 = TargetHudHealthMid
            else
                HealthBar.BackgroundColor3 = TargetHudHealthLow
            end
            
            BindHealthTracker(CurrentTargetPlayer)
            ToggleHUD(true)
        else
            ToggleHUD(false)
            LastLoggedHudTargetId = 0
        end
    else
        ToggleHUD(false)
        LastLoggedHudTargetId = 0
    end

    if SilentAimEnabled and LookAtEnabled and LocalPlayer.Character then
        local Root = LocalPlayer.Character:FindFirstChild("HumanoidRootPart")
        local Humanoid = LocalPlayer.Character:FindFirstChildOfClass("Humanoid")
        if Root and Humanoid and Humanoid.Health > 0 and not AntiAimEnabled then
            if CurrentAimTargetPosition then
                Humanoid.AutoRotate = false
                local lookVector = Vector3.new(CurrentAimTargetPosition.X, Root.Position.Y, CurrentAimTargetPosition.Z)
                Root.CFrame = CFrame.lookAt(Root.Position, lookVector)
            else
                Humanoid.AutoRotate = true
            end
        end
    end

    if AntiAimEnabled and LocalPlayer.Character then
        local Root = LocalPlayer.Character:FindFirstChild("HumanoidRootPart")
        local Humanoid = LocalPlayer.Character:FindFirstChildOfClass("Humanoid")
        if Root and Humanoid and Humanoid.Health > 0 then
            Humanoid.AutoRotate = false
            if AntiAimMode == "Spin" then
                spinAngle = (spinAngle + AntiAimSpeed) % 360
                Root.CFrame = CFrame.new(Root.Position) * CFrame.Angles(0, math.rad(spinAngle), 0)
            elseif AntiAimMode == "Jitter" then
                local intensity = 1
                if JitterMode == "Multi" then intensity = math.random(1, 5)
                elseif JitterMode == "5x always" then intensity = 5
                elseif JitterMode == "3x always" then intensity = 3
                elseif JitterMode == "2x always" then intensity = 2
                elseif JitterMode == "random" then intensity = math.random(1, 5)
                else intensity = math.random(1, 5) end
                jitterToggle = not jitterToggle
                local _, cameraY, _ = Camera.CFrame:ToOrientation()
                local jitterOffset = jitterToggle and math.rad(22.5 * intensity) or math.rad(-22.5 * intensity)
                Root.CFrame = CFrame.new(Root.Position) * CFrame.Angles(0, cameraY + jitterOffset, 0)
                local LowerTorso = LocalPlayer.Character:FindFirstChild("LowerTorso") or LocalPlayer.Character:FindFirstChild("Torso")
                if LowerTorso and LowerTorso:FindFirstChild("RootJoint") then
                    LowerTorso.RootJoint.Transform = CFrame.Angles(0, jitterOffset, 0)
                end
            end
        end
    else
        if LocalPlayer.Character then
            local Humanoid = LocalPlayer.Character:FindFirstChildOfClass("Humanoid")
            if Humanoid then
                if not LookAtEnabled or (LookAtEnabled and not CurrentAimTargetPosition) then
                    Humanoid.AutoRotate = true
                end
            end
            local LowerTorso = LocalPlayer.Character:FindFirstChild("LowerTorso") or LocalPlayer.Character:FindFirstChild("Torso")
            if LowerTorso and LowerTorso:FindFirstChild("RootJoint") then
                LowerTorso.RootJoint.Transform = CFrame.new()
            end
        end
    end

    if ThirdPersonEnabled then
        local char = LocalPlayer.Character
        local hum = char and char:FindFirstChildOfClass("Humanoid")
        if hum then
            hum.CameraOffset = Vector3.new(1.5, 2, 0)
            LocalPlayer.CameraMinZoomDistance = ThirdPersonDistance
            LocalPlayer.CameraMaxZoomDistance = ThirdPersonDistance
            if Camera.CameraType ~= Enum.CameraType.Custom then
                Camera.CameraType = Enum.CameraType.Custom
            end
        end
    else
        local char = LocalPlayer.Character
        local hum = char and char:FindFirstChildOfClass("Humanoid")
        if hum and hum.CameraOffset ~= Vector3.new(0, 0, 0) then
            ResetCamera()
        end
    end

    local blurEffect = Lighting:FindFirstChild("hooksenseMotionBlur")
    if MotionBlurEnabled then
        if not blurEffect then
            blurEffect = Instance.new("BlurEffect")
            blurEffect.Name = "hooksenseMotionBlur"
            blurEffect.Parent = Lighting
        end
        local currentLookVector = Camera.CFrame.LookVector
        local angleDifference = math.acos(math.clamp(currentLookVector:Dot(LastCameraRotation), -1, 1))
        local blurTarget = math.clamp(angleDifference * 45 * MotionBlurIntensity, 0, 56)
        
        blurEffect.Size = blurEffect.Size + (blurTarget - blurEffect.Size) * 0.25
        LastCameraRotation = currentLookVector
    else
        if blurEffect then blurEffect:Destroy() end
    end
end)

task.spawn(function()
    while true do
        task.wait()
        if BhopEnabled and LocalPlayer.Character then
            local Humanoid = LocalPlayer.Character:FindFirstChildOfClass("Humanoid")
            local Root = LocalPlayer.Character:FindFirstChild("HumanoidRootPart")
            if Humanoid and Root then
                local MoveDirection = Humanoid.MoveDirection
                if MoveDirection.Magnitude > 0 then
                    if Humanoid.FloorMaterial ~= Enum.Material.Air then
                        Humanoid:ChangeState(Enum.HumanoidStateType.Jumping)
                    end
                    Root.Velocity = Vector3.new(MoveDirection.X * (Humanoid.WalkSpeed * BhopSpeedMultiplier), Root.Velocity.Y, MoveDirection.Z * (Humanoid.WalkSpeed * BhopSpeedMultiplier))
                end
            end
        end
    end
end)

-- Silent Aim Hook Metamethod
local OldNamecall
OldNamecall = hookmetamethod(game, "__namecall", newcclosure(function(Self, ...)
    if checkcaller() then return OldNamecall(Self, ...) end
    local Args = { ... }
    local Method = getnamecallmethod()
    local SelfClass = ""
    pcall(function()
        if Self and typeof(Self) == "Instance" then SelfClass = Self.ClassName end
    end)

    if SilentAimEnabled and CurrentAimTargetPosition then
        if (Method == "ScreenPointToRay" or Method == "ViewportPointToRay") and SelfClass == "Camera" then
            return Ray.new(Camera.CFrame.Position, (CurrentAimTargetPosition - Camera.CFrame.Position).Unit)
        end
        if Method == "Raycast" and SelfClass == "Workspace" then
            if BulletTPEnabled then
                Args[1] = CurrentAimTargetPosition - (Args[2].Unit * 1)
                Args[2] = Args[2].Unit * 5
            else
                Args[2] = (CurrentAimTargetPosition - Args[1]).Unit * Args[2].Magnitude
            end
            return OldNamecall(Self, table.unpack(Args))
        end
        if (Method == "FindPartOnRay" or Method == "FindPartOnRayWithIgnoreList" or Method == "FindPartOnRayWithWhitelist") and SelfClass == "Workspace" then
            local CurrentRay = Args[1]
            if CurrentRay and typeof(CurrentRay) == "Ray" then
                if BulletTPEnabled then
                    local NewOrigin = CurrentAimTargetPosition - (CurrentRay.Direction.Unit * 1)
                    Args[1] = Ray.new(NewOrigin, CurrentRay.Direction.Unit * 5)
                else
                    Args[1] = Ray.new(CurrentRay.Origin, (CurrentAimTargetPosition - CurrentRay.Origin).Unit * CurrentRay.Direction.Magnitude)
                end
                return OldNamecall(Self, table.unpack(Args))
            end
        end
    end
    return OldNamecall(Self, ...)
end))

local Tabs = {
    Main = Window:AddTab("Main"),
    Aimbot = Window:AddTab("Aimbot"),
    HitEffects = Window:AddTab("Hits"),
    ESP = Window:AddTab("Esp"),
    Movement = Window:AddTab("Character"),
    World = Window:AddTab("World"),
    Addons = Window:AddTab("Misc"),
    ['UI'] = Window:AddTab("UI setting")
}

local Options = getgenv().Options
local Toggles = getgenv().Toggles

-- [Aimbot Tab Components]
local MobileAimbotBox = Tabs.Aimbot:AddLeftGroupbox("Aimbot")
local MobileAimbotSettings = Tabs.Aimbot:AddRightGroupbox("Aimbot Options")

MobileAimbotBox:AddToggle("MobileAimbotToggle", { Text = "Enable Aimbot", Default = false })
    :AddKeyPicker("MobileAimbotKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Mobile Aimbot Bind" })

Toggles.MobileAimbotToggle:OnChanged(function()
    MobileAimbotEnabled = Toggles.MobileAimbotToggle.Value
end)

MobileAimbotBox:AddSlider("AimbotSmoothSlider", { Text = "Aimbot Smoothness", Default = 0.1, Min = 0.01, Max = 1, Rounding = 2 })
Options.AimbotSmoothSlider:OnChanged(function()
    AimbotSmoothness = Options.AimbotSmoothSlider.Value
end)

MobileAimbotBox:AddSlider("JumpSmoothSlider", { Text = "Jump Smooth", Default = 1, Min = 1, Max = 100, Rounding = 0, Suffix = "%" })
Options.JumpSmoothSlider:OnChanged(function()
    JumpSmooth = Options.JumpSmoothSlider.Value
end)

MobileAimbotBox:AddSlider("SmoothXSlider", { Text = "Smooth X", Default = 1, Min = 1, Max = 100, Rounding = 0, Suffix = "%" })
Options.SmoothXSlider:OnChanged(function()
    SmoothX = Options.SmoothXSlider.Value
end)

MobileAimbotBox:AddSlider("SmoothZSlider", { Text = "Smooth Z", Default = 1, Min = 1, Max = 100, Rounding = 0, Suffix = "%" })
Options.SmoothZSlider:OnChanged(function()
    SmoothZ = Options.SmoothZSlider.Value
end)

MobileAimbotBox:AddToggle("AutoPredictionToggle", { Text = "Enable Auto Prediction", Default = false })
Toggles.AutoPredictionToggle:OnChanged(function()
    AutoPredictionEnabled = Toggles.AutoPredictionToggle.Value
end)

MobileAimbotBox:AddSlider("PredictionSlider", { Text = "Prediction Multiplier", Default = 0.1, Min = 0.0, Max = 5.0, Rounding = 2 })
Options.PredictionSlider:OnChanged(function()
    PredictionValue = Options.PredictionSlider.Value
end)

MobileAimbotSettings:AddDropdown("MobileTargetPartDropdown", { Text = "Aimbot Target Part", Values = {"Head", "HumanoidRootPart"}, Default = 1, Multi = false })
Options.MobileTargetPartDropdown:OnChanged(function()
    AimbotTargetPart = Options.MobileTargetPartDropdown.Value
end)

-- [Main Tab Components]
local LeftGroupBox = Tabs.Main:AddLeftGroupbox("Silent Aim")
local PermLockGroupBox = Tabs.Main:AddLeftGroupbox("Permanent Lock Settings")
local TargetGroupBox = Tabs.Main:AddLeftGroupbox("Targeting Options")
local FOVGroupBox = Tabs.Main:AddRightGroupbox("FOV Settings")
local FOVFillGroupBox = Tabs.Main:AddRightGroupbox("FOV Dynamic Gradient Fill")
local TracerGroupBox = Tabs.Main:AddRightGroupbox("Tracer Line Settings")

LeftGroupBox:AddToggle("SilentAimToggle", { Text = "Enable Silent Aim", Default = false })
    :AddKeyPicker("SilentAimKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Silent Aim Bind" })

Toggles.SilentAimToggle:OnChanged(function()
    SilentAimEnabled = Toggles.SilentAimToggle.Value
end)

LeftGroupBox:AddToggle("ResolverToggle", { Text = "Enable Resolver", Default = false })
Toggles.ResolverToggle:OnChanged(function()
    ResolverEnabled = Toggles.ResolverToggle.Value
end)

LeftGroupBox:AddToggle("LookAtToggle", { Text = "Enable Look at Target", Default = false })
    :AddKeyPicker("LookAtKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Look At Bind" })

Toggles.LookAtToggle:OnChanged(function()
    LookAtEnabled = Toggles.LookAtToggle.Value
end)

LeftGroupBox:AddToggle("BulletTPToggle", { Text = "Enable Bullet TP", Default = false })
    :AddKeyPicker("BulletTPKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Bullet TP Bind" })

Toggles.BulletTPToggle:OnChanged(function()
    BulletTPEnabled = Toggles.BulletTPToggle.Value
end)

LeftGroupBox:AddToggle("WallCheckToggle", { Text = "Enable Wall Check", Default = false })
Toggles.WallCheckToggle:OnChanged(function()
    WallCheckEnabled = Toggles.WallCheckToggle.Value
end)

LeftGroupBox:AddToggle("TeamCheckToggle", { Text = "Enable Team Check", Default = false })
Toggles.TeamCheckToggle:OnChanged(function()
    TeamCheckEnabled = Toggles.TeamCheckToggle.Value
end)

PermLockGroupBox:AddToggle("PermLockToggle", { Text = "Enable Perm Lock-On", Default = false })
    :AddKeyPicker("PermLockKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Perm Lock Bind" })

Toggles.PermLockToggle:OnChanged(function()
    PermLockEnabled = Toggles.PermLockToggle.Value
end)

PermLockGroupBox:AddDropdown("PermTargetDropdown", { Text = "Targets Queue List", Values = {"No Targets Added"}, Default = 1, Multi = false })

local function RefreshDropdownValues()
    if #PermTargetList == 0 then
        Options.PermTargetDropdown:SetValues({"No Targets Added"})
        Options.PermTargetDropdown:SetValue(1)
    else
        for i = #PermTargetList, 1, -1 do
            if not Players:FindFirstChild(PermTargetList[i]) then
                table.remove(PermTargetList, i)
            end
        end
        if #PermTargetList == 0 then
            Options.PermTargetDropdown:SetValues({"No Targets Added"})
            Options.PermTargetDropdown:SetValue(1)
        else
            Options.PermTargetDropdown:SetValues(PermTargetList)
            Options.PermTargetDropdown:SetValue(PermTargetList[1])
        end
    end
end

Players.PlayerRemoving:Connect(function(player)
    task.wait(0.1)
    RefreshDropdownValues()
end)
Players.PlayerAdded:Connect(function(player)
    task.wait(0.1)
    RefreshDropdownValues()
end)

PermLockGroupBox:AddButton({Text = "Clear All Targets", Func = function()
    PermTargetList = {}
    RefreshDropdownValues()
    Library:Notify("Permanent Target List Cleared!")
end})

PermLockGroupBox:AddInput("PermTargetInput", { Placeholder = "Enter Display or Username...", Text = "", Numeric = false, Finished = false, })
PermLockGroupBox:AddButton({Text = "Target Player", Func = function()
    local enteredText = Options.PermTargetInput.Value
    if enteredText and enteredText ~= "" then
        enteredText = string.gsub(enteredText, "%s+", "")
        local matchFound = nil
        for _, p in ipairs(Players:GetPlayers()) do
            local nameMatch = string.find(string.lower(p.Name), string.lower(enteredText))
            local dispMatch = string.find(string.lower(p.DisplayName), string.lower(enteredText))
            if nameMatch or dispMatch then
                matchFound = p.Name
                break
            end
        end
        if matchFound then
            if not table.find(PermTargetList, matchFound) then
                table.insert(PermTargetList, matchFound)
                RefreshDropdownValues()
                Options.PermTargetDropdown:SetValue(matchFound)
                Library:Notify("Successfully Targeted: " .. matchFound)
            else
                Library:Notify("Player already exists in list!")
            end
        else
            Library:Notify("No matching player found on this server!")
        end
        Options.PermTargetInput:SetValue("")
    else
        Library:Notify("Please enter a valid player name.")
    end
end})

TargetGroupBox:AddDropdown("TargetPartDropdown", { Text = "Target Lock Part", Values = {"Head", "HumanoidRootPart", "Root to Head", "Closet"}, Default = 1, Multi = false })
Options.TargetPartDropdown:OnChanged(function()
    TargetPartMode = Options.TargetPartDropdown.Value
end)

TargetGroupBox:AddSlider("TransitionSpeedSlider", { Text = "Root Transfer Speed (Root to Head)", Default = 5, Min = 1, Max = 30, Rounding = 1 })
Options.TransitionSpeedSlider:OnChanged(function()
    TransitionSpeed = Options.TransitionSpeedSlider.Value
end)

TargetGroupBox:AddSlider("MaxDistanceSlider", { Text = "Max Lock Distance (Studs)", Default = 10000, Min = 1, Max = 99999999, Rounding = 0 })
Options.MaxDistanceSlider:OnChanged(function()
    MaxTargetDistance = Options.MaxDistanceSlider.Value
end)

FOVGroupBox:AddToggle("FOVVisibleToggle", { Text = "Show FOV Circle", Default = true })
Toggles.FOVVisibleToggle:OnChanged(function()
    FOVVisible = Toggles.FOVVisibleToggle.Value
end)

FOVGroupBox:AddSlider("FOVSlider", { Text = "FOV Size Radius", Default = 100, Min = 40, Max = 800, Rounding = 0 })
Options.FOVSlider:OnChanged(function()
    FOVSize = Options.FOVSlider.Value
end)

FOVGroupBox:AddLabel("FOV Line Color"):AddColorPicker("FOVCircleColorPicker", { Default = Color3.fromRGB(255, 255, 255) })
Options.FOVCircleColorPicker:OnChanged(function()
    FOVCircleColor = Options.FOVCircleColorPicker.Value
end)

FOVGroupBox:AddLabel("FOV Outline Color"):AddColorPicker("FOVCircleOutlineColorPicker", { Default = Color3.fromRGB(0, 0, 0) })
Options.FOVCircleOutlineColorPicker:OnChanged(function()
    FOVCircleOutlineColor = Options.FOVCircleOutlineColorPicker.Value
end)

FOVFillGroupBox:AddToggle("FOVFillToggle", { Text = "Enable FOV Fill", Default = false })
Toggles.FOVFillToggle:OnChanged(function()
    FOVFillEnabled = Toggles.FOVFillToggle.Value
end)

FOVFillGroupBox:AddSlider("FOVFillTransparencySlider", { Text = "FOV Fill Opacity", Default = 0.2, Min = 0, Max = 1, Rounding = 2 })
Options.FOVFillTransparencySlider:OnChanged(function()
    FOVFillTransparency = Options.FOVFillTransparencySlider.Value
end)

FOVFillGroupBox:AddLabel("Fill Color 1 (Top)"):AddColorPicker("FOVFillColor1Picker", { Default = Color3.fromRGB(255, 0, 0) })
Options.FOVFillColor1Picker:OnChanged(function()
    FOVFillColor1 = Options.FOVFillColor1Picker.Value
end)

FOVFillGroupBox:AddLabel("Fill Color 2 (Mid)"):AddColorPicker("FOVFillColor2Picker", { Default = Color3.fromRGB(0, 255, 0) })
Options.FOVFillColor2Picker:OnChanged(function()
    FOVFillColor2 = Options.FOVFillColor2Picker.Value
end)

FOVFillGroupBox:AddLabel("Fill Color 3 (Bottom)"):AddColorPicker("FOVFillColor3Picker", { Default = Color3.fromRGB(0, 0, 255) })
Options.FOVFillColor3Picker:OnChanged(function()
    FOVFillColor3 = Options.FOVFillColor3Picker.Value
end)

FOVFillGroupBox:AddToggle("FOVFillRotateToggle", { Text = "Rotate FOV Gradient", Default = false })
Toggles.FOVFillRotateToggle:OnChanged(function()
    FOVFillRotateEnabled = Toggles.FOVFillRotateToggle.Value
end)

FOVFillGroupBox:AddSlider("FOVFillRotateSpeedSlider", { Text = "Gradient Rotation Speed", Default = 1, Min = 1, Max = 10, Rounding = 1 })
Options.FOVFillRotateSpeedSlider:OnChanged(function()
    FOVFillRotateSpeed = Options.FOVFillRotateSpeedSlider.Value
end)

TracerGroupBox:AddToggle("TracerVisibleToggle", { Text = "Enable Tracer Line", Default = true })
Toggles.TracerVisibleToggle:OnChanged(function()
    TracerEnabled = Toggles.TracerVisibleToggle.Value
end)

TracerGroupBox:AddSlider("TracerThicknessSlider", { Text = "Tracer Line Thickness", Default = 1.0, Min = 0.5, Max = 5.0, Rounding = 1 })
Options.TracerThicknessSlider:OnChanged(function()
    TracerThickness = Options.TracerThicknessSlider.Value
end)

TracerGroupBox:AddSlider("TracerOutlineThicknessSlider", { Text = "Tracer Outline Thickness", Default = 3.0, Min = 1.0, Max = 8.0, Rounding = 1 })
Options.TracerOutlineThicknessSlider:OnChanged(function()
    TracerOutlineThickness = Options.TracerOutlineThicknessSlider.Value
end)

TracerGroupBox:AddLabel("Tracer Main Color"):AddColorPicker("TracerLineColorPicker", { Default = Color3.fromRGB(255, 0, 0) })
Options.TracerLineColorPicker:OnChanged(function()
    TracerLineColor = Options.TracerLineColorPicker.Value
end)

TracerGroupBox:AddLabel("Tracer Outline Color"):AddColorPicker("TracerLineOutlineColorPicker", { Default = Color3.fromRGB(0, 0, 0) })
Options.TracerLineOutlineColorPicker:OnChanged(function()
    TracerLineOutlineColor = Options.TracerLineOutlineColorPicker.Value
end)

-- [HitEffects Tab Components]
local SoundLeftBox = Tabs.HitEffects:AddLeftGroupbox("Hit Sound")
local OverlayLeftBox = Tabs.HitEffects:AddLeftGroupbox("Hit Overlay") 
local NotifyRightBox = Tabs.HitEffects:AddRightGroupbox("Hit Notification Custom System")

SoundLeftBox:AddDropdown("HitSoundDropdown", { Text = "Target Hit Sound (เปิด traget hud ก่อน)", Values = {"None", "Spark", "Neverlose", "Rust", "Fatality", "Fatality 2", "Minecraft xp", "Minecraft", "Crack", "Skeet"}, Default = 1, Multi = false })
Options.HitSoundDropdown:OnChanged(function()
    HitSoundMode = Options.HitSoundDropdown.Value
end)

SoundLeftBox:AddSlider("HitSoundVolumeSlider", { Text = "Hit Sound Volume Level", Default = 2.0, Min = 0.0, Max = 5.0, Rounding = 1 })
Options.HitSoundVolumeSlider:OnChanged(function()
    HitSoundVolume = Options.HitSoundVolumeSlider.Value
end)

OverlayLeftBox:AddToggle("HitOverlayToggle", { Text = "Enable Hit Overlay", Default = false })
Toggles.HitOverlayToggle:OnChanged(function()
    HitOverlayEnabled = Toggles.HitOverlayToggle.Value
end)

OverlayLeftBox:AddLabel("Overlay Border Color"):AddColorPicker("HitOverlayColorPicker", { Default = Color3.fromRGB(255, 0, 0) })
Options.HitOverlayColorPicker:OnChanged(function()
    HitOverlayColor = Options.HitOverlayColorPicker.Value
end)

NotifyRightBox:AddToggle("HitNotifyToggle", { Text = "Enable Hit Notification", Default = false })
Toggles.HitNotifyToggle:OnChanged(function()
    HitNotifyEnabled = Toggles.HitNotifyToggle.Value
end)

NotifyRightBox:AddSlider("HitNotifyDurationSlider", { Text = "Notification Duration (s)", Default = 2.5, Min = 0.5, Max = 5.0, Rounding = 1 })
Options.HitNotifyDurationSlider:OnChanged(function()
    HitNotifyDuration = Options.HitNotifyDurationSlider.Value
end)

NotifyRightBox:AddSlider("HitNotifyTransparencySlider", { Text = "Notification Opacity/Transparency", Default = 0, Min = 0, Max = 1, Rounding = 2 })
Options.HitNotifyTransparencySlider:OnChanged(function()
    HitNotifyTransparency = Options.HitNotifyTransparencySlider.Value
end)

NotifyRightBox:AddSlider("HitNotifyPosXSlider", { Text = "Position X Offset (%)", Default = 50, Min = 1, Max = 100, Rounding = 0 })
Options.HitNotifyPosXSlider:OnChanged(function()
    HitNotifyPosX = Options.HitNotifyPosXSlider.Value
    CenterNotifyContainer.Position = UDim2.new(HitNotifyPosX / 100, 0, HitNotifyPosY / 100, 0)
end)

NotifyRightBox:AddSlider("HitNotifyPosYSlider", { Text = "Position Y Offset (%)", Default = 65, Min = 1, Max = 100, Rounding = 0 })
Options.HitNotifyPosYSlider:OnChanged(function()
    HitNotifyPosY = Options.HitNotifyPosYSlider.Value
    CenterNotifyContainer.Position = UDim2.new(HitNotifyPosX / 100, 0, HitNotifyPosY / 100, 0)
end)

NotifyRightBox:AddDropdown("HitNotifyFontDropdown", { Text = "Hit Notify Custom Font", Values = RobloxFontsList, Default = table.find(RobloxFontsList, "Cartoon") or 1, Multi = false })
Options.HitNotifyFontDropdown:OnChanged(function()
    local SelectedFont = Enum.Font[Options.HitNotifyFontDropdown.Value]
    if SelectedFont then
        HitNotifyFont = SelectedFont
    end
end)

NotifyRightBox:AddInput("CustomHitNotifyInput", { Placeholder = "Format: {name} | {part} | {dmg} | {weapon}", Text = "Hit {name} in the {part} for {dmg} dmg with {weapon}", Numeric = false, Finished = true })
Options.CustomHitNotifyInput:OnChanged(function()
    if Options.CustomHitNotifyInput.Value and Options.CustomHitNotifyInput.Value ~= "" then
        HitNotifyTemplate = Options.CustomHitNotifyInput.Value
    end
end)

-- [ESP Tab Components - Integrated UELinoriaLib Drawing ESP]
local DrawingFonts = {
    ["UI"] = 0,
    ["System"] = 1,
    ["Plex"] = 2,
    ["Monospace"] = 3
}
local DrawingFontNames = {"UI", "System", "Plex", "Monospace"}

local function GetColor(optionName, defaultColor)
    local fallback = defaultColor or Color3.fromRGB(255, 255, 255)
    if not Options then return fallback end
    local opt = Options[optionName]
    if not opt then return fallback end

    if typeof(opt) == "Color3" then
        return opt
    elseif typeof(opt) == "table" then
        if typeof(opt.Value) == "Color3" then
            return opt.Value
        elseif typeof(opt.Color) == "Color3" then
            return opt.Color
        elseif opt[1] and typeof(opt[1]) == "number" then
            return Color3.new(opt[1], opt[2], opt[3])
        end
    elseif typeof(opt) == "UserData" or typeof(opt) == "RBXScriptConnection" then
        if opt.Value and typeof(opt.Value) == "Color3" then
            return opt.Value
        end
    end
    return fallback
end

local function CreateLine(thickness, color)
    local line = Drawing.new("Line")
    line.Thickness = thickness or 1
    line.Color = color or Color3.fromRGB(0, 0, 0)
    line.Transparency = 1
    line.Visible = false
    return line
end

local function CreateText()
    local text = Drawing.new("Text")
    text.Size = 13
    text.Center = true
    text.Outline = true
    text.OutlineColor = Color3.fromRGB(0, 0, 0)
    text.Font = 2
    text.Visible = false
    return text
end

local function CreateSquare(filled)
    local sq = Drawing.new("Square")
    sq.Thickness = 1
    sq.Filled = (filled == true)
    sq.Transparency = 1
    sq.Visible = false
    return sq
end

local ESP_Drawing_Storage = {}
local function ImplementESPSetup(holder)
    pcall(function()
        holder.BoxLines = {CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1)}
        holder.BoxOutlines = {
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1),
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1)
        }
        holder.CornerLines = {
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1),
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1)
        }
        holder.CornerOutlines = {
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1),
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1),
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1),
            CreateLine(1), CreateLine(1), CreateLine(1), CreateLine(1)
        }

        holder.HealthOutline = CreateSquare(true)
        holder.HealthBar = CreateSquare(true)
        holder.HealthText = CreateText()
        holder.Name = CreateText()
        holder.Distance = CreateText()
        holder.SmoothHealth = nil

        if holder.HealthOutline then holder.HealthOutline.Color = Color3.fromRGB(0, 0, 0) end
        if holder.HealthText then 
            holder.HealthText.Size = 11 
            holder.HealthText.Center = true 
        end
    end)
end

local function CreateDrawingESP(player)
    if player == LocalPlayer then return end
    if ESP_Drawing_Storage[player] then return end
    ESP_Drawing_Storage[player] = {}
    ImplementESPSetup(ESP_Drawing_Storage[player])
end

local function RemoveDrawingESP(player)
    if ESP_Drawing_Storage[player] then
        pcall(function()
            for _, obj in pairs(ESP_Drawing_Storage[player]) do
                if type(obj) == "table" then
                    for _, subObj in pairs(obj) do
                        if subObj and subObj.Remove then subObj:Remove() end
                    end
                elseif type(obj) == "userdata" and obj.Remove then
                    obj:Remove()
                end
            end
        end)
        ESP_Drawing_Storage[player] = nil
    end
end

for _, p in ipairs(Players:GetPlayers()) do CreateDrawingESP(p) end
Players.PlayerAdded:Connect(CreateDrawingESP)
Players.PlayerRemoving:Connect(RemoveDrawingESP)

local function SetVisibilityFalse(esp)
    pcall(function()
        if esp.BoxLines then for i = 1, 4 do esp.BoxLines[i].Visible = false end end
        if esp.BoxOutlines then for i = 1, 8 do esp.BoxOutlines[i].Visible = false end end
        if esp.CornerLines then for i = 1, 8 do esp.CornerLines[i].Visible = false end end
        if esp.CornerOutlines then for i = 1, 16 do esp.CornerOutlines[i].Visible = false end end
        if esp.HealthBar then esp.HealthBar.Visible = false end
        if esp.HealthOutline then esp.HealthOutline.Visible = false end
        if esp.HealthText then esp.HealthText.Visible = false end
        if esp.Name then esp.Name.Visible = false end
        if esp.Distance then esp.Distance.Visible = false end
    end)
end

RunService.RenderStepped:Connect(function()
    pcall(function()
        local Camera = workspace.CurrentCamera
        if not Camera then return end

        local espMaster = Toggles.EspMaster and Toggles.EspMaster.Value
        if not espMaster then
            for _, esp in pairs(ESP_Drawing_Storage) do SetVisibilityFalse(esp) end
            return
        end

        local boxColor = GetColor("BoxColor", Color3.fromRGB(255, 255, 255))
        local cornerColor = GetColor("CornerColor", Color3.fromRGB(0, 210, 255))
        local nameColor = GetColor("NameColor", Color3.fromRGB(255, 255, 255))
        local distColor = GetColor("DistColor", Color3.fromRGB(255, 255, 255))
        local hpTextColor = GetColor("HPTextColor", Color3.fromRGB(255, 255, 255))
        local nameStyle = Options.NameStyleDropdown and Options.NameStyleDropdown.Value or "Username"
        
        local selectedFontName = Options.EspFontDropdown and Options.EspFontDropdown.Value or "Plex"
        local currentDrawingFont = DrawingFonts[selectedFontName] or 2

        local hpFullColor = GetColor("HPFullColor", Color3.fromRGB(0, 255, 0))
        local hpHalfColor = GetColor("HPHalfColor", Color3.fromRGB(255, 170, 0))
        local hpLowColor = GetColor("HPLowColor", Color3.fromRGB(255, 0, 0))
        local lerpAlpha = Options.HealthLerpSlider and Options.HealthLerpSlider.Value or 0.2

        for player, esp in pairs(ESP_Drawing_Storage) do
            pcall(function()
                local character = player.Character
                local rootPart = character and character:FindFirstChild("HumanoidRootPart")
                local humanoid = character and character:FindFirstChildOfClass("Humanoid")

                if character and rootPart and humanoid and humanoid.Health > 0 then
                    if TeamCheckEnabled and player.Team == LocalPlayer.Team then
                        esp.SmoothHealth = nil
                        SetVisibilityFalse(esp)
                        return
                    end

                    local rootPos, onScreen = Camera:WorldToViewportPoint(rootPart.Position)
                    
                    if onScreen and rootPos.Z > 0 then
                        local headOffset = rootPart.CFrame * CFrame.new(0, 2.5, 0)
                        local feetOffset = rootPart.CFrame * CFrame.new(0, -3.0, 0)
                        
                        local headPos = Camera:WorldToViewportPoint(headOffset.Position)
                        local feetPos = Camera:WorldToViewportPoint(feetOffset.Position)
                        
                        local height = math.abs(headPos.Y - feetPos.Y)
                        local width = height * 0.48
                        local boxX = math.round(rootPos.X - (width / 2))
                        local boxY = math.round(headPos.Y)
                        
                        local selectedName = (nameStyle == "Display Name") and player.DisplayName or player.Name
                        local maxHp = (humanoid.MaxHealth > 0) and humanoid.MaxHealth or 100
                        local targetHp = math.clamp(humanoid.Health, 0, maxHp)
                        
                        if not esp.SmoothHealth then 
                            esp.SmoothHealth = targetHp 
                        else
                            esp.SmoothHealth = esp.SmoothHealth + (targetHp - esp.SmoothHealth) * lerpAlpha
                        end

                        local pct = math.clamp(esp.SmoothHealth / maxHp, 0, 1)
                        local mathWidth, mathHeight = math.round(width), math.round(height)

                        local textSize = math.clamp(math.round(mathHeight * 0.28), 9, 14)
                        local hpTextSize = math.clamp(math.round(mathHeight * 0.22), 8, 12)

                        if esp.Name then esp.Name.Font = currentDrawingFont; esp.Name.Size = textSize end
                        if esp.Distance then esp.Distance.Font = currentDrawingFont; esp.Distance.Size = textSize end
                        if esp.HealthText then esp.HealthText.Font = currentDrawingFont; esp.HealthText.Size = hpTextSize end

                        -- Corner Box
                        local corner = esp.CornerLines
                        local cornerOut = esp.CornerOutlines
                        local isCorner = Toggles.EspCornerBox and Toggles.EspCornerBox.Value
                        local isNormalBox = Toggles.EspBox and Toggles.EspBox.Value

                        if isCorner then
                            local cl = math.clamp(math.round(mathWidth * 0.22), 3, 12)
                            corner[1].From, corner[1].To = Vector2.new(boxX, boxY), Vector2.new(boxX + cl, boxY)
                            corner[2].From, corner[2].To = Vector2.new(boxX, boxY), Vector2.new(boxX, boxY + cl)
                            corner[3].From, corner[3].To = Vector2.new(boxX + mathWidth, boxY), Vector2.new(boxX + mathWidth - cl, boxY)
                            corner[4].From, corner[4].To = Vector2.new(boxX + mathWidth, boxY), Vector2.new(boxX + mathWidth, boxY + cl)
                            corner[5].From, corner[5].To = Vector2.new(boxX, boxY + mathHeight), Vector2.new(boxX + cl, boxY + mathHeight)
                            corner[6].From, corner[6].To = Vector2.new(boxX, boxY + mathHeight), Vector2.new(boxX, boxY + mathHeight - cl)
                            corner[7].From, corner[7].To = Vector2.new(boxX + mathWidth, boxY + mathHeight), Vector2.new(boxX + mathWidth - cl, boxY + mathHeight)
                            corner[8].From, corner[8].To = Vector2.new(boxX + mathWidth, boxY + mathHeight), Vector2.new(boxX + mathWidth, boxY + mathHeight - cl)

                            cornerOut[1].From, cornerOut[1].To = Vector2.new(boxX - 1, boxY - 1), Vector2.new(boxX + cl + 1, boxY - 1)
                            cornerOut[2].From, cornerOut[2].To = Vector2.new(boxX - 1, boxY - 1), Vector2.new(boxX - 1, boxY + cl + 1)
                            cornerOut[3].From, cornerOut[3].To = Vector2.new(boxX + mathWidth + 1, boxY - 1), Vector2.new(boxX + mathWidth - cl - 1, boxY - 1)
                            cornerOut[4].From, cornerOut[4].To = Vector2.new(boxX + mathWidth + 1, boxY - 1), Vector2.new(boxX + mathWidth + 1, boxY + cl + 1)
                            cornerOut[5].From, cornerOut[5].To = Vector2.new(boxX - 1, boxY + mathHeight + 1), Vector2.new(boxX + cl + 1, boxY + mathHeight + 1)
                            cornerOut[6].From, cornerOut[6].To = Vector2.new(boxX - 1, boxY + mathHeight + 1), Vector2.new(boxX - 1, boxY + mathHeight - cl - 1)
                            cornerOut[7].From, cornerOut[7].To = Vector2.new(boxX + mathWidth + 1, boxY + mathHeight + 1), Vector2.new(boxX + mathWidth - cl - 1, boxY + mathHeight + 1)
                            cornerOut[8].From, cornerOut[8].To = Vector2.new(boxX + mathWidth + 1, boxY + mathHeight + 1), Vector2.new(boxX + mathWidth + 1, boxY + mathHeight - cl - 1)
                            cornerOut[9].From, cornerOut[9].To = Vector2.new(boxX + 1, boxY + 1), Vector2.new(boxX + cl - 1, boxY + 1)
                            cornerOut[10].From, cornerOut[10].To = Vector2.new(boxX + 1, boxY + 1), Vector2.new(boxX + 1, boxY + cl - 1)
                            cornerOut[11].From, cornerOut[11].To = Vector2.new(boxX + mathWidth - 1, boxY + 1), Vector2.new(boxX + mathWidth - cl + 1, boxY + 1)
                            cornerOut[12].From, cornerOut[12].To = Vector2.new(boxX + mathWidth - 1, boxY + 1), Vector2.new(boxX + mathWidth - 1, boxY + cl - 1)
                            cornerOut[13].From, cornerOut[13].To = Vector2.new(boxX + 1, boxY + mathHeight - 1), Vector2.new(boxX + cl - 1, boxY + mathHeight - 1)
                            cornerOut[14].From, cornerOut[14].To = Vector2.new(boxX + 1, boxY + mathHeight - 1), Vector2.new(boxX + 1, boxY + mathHeight - cl + 1)
                            cornerOut[15].From, cornerOut[15].To = Vector2.new(boxX + mathWidth - 1, boxY + mathHeight - 1), Vector2.new(boxX + mathWidth - cl + 1, boxY + mathHeight - 1)
                            cornerOut[16].From, cornerOut[16].To = Vector2.new(boxX + mathWidth - 1, boxY + mathHeight - 1), Vector2.new(boxX + mathWidth - 1, boxY + mathHeight - cl + 1)

                            for i = 1, 8 do corner[i].Color = cornerColor; corner[i].Visible = true end
                            for i = 1, 16 do cornerOut[i].Color = Color3.fromRGB(0, 0, 0); cornerOut[i].Visible = true end
                        else
                            for i = 1, 8 do corner[i].Visible = false end
                            for i = 1, 16 do cornerOut[i].Visible = false end
                        end

                        -- Normal Box
                        local lines = esp.BoxLines
                        local outs = esp.BoxOutlines
                        if isNormalBox and not isCorner then
                            lines[1].From, lines[1].To = Vector2.new(boxX, boxY), Vector2.new(boxX + mathWidth, boxY)
                            lines[2].From, lines[2].To = Vector2.new(boxX + mathWidth, boxY), Vector2.new(boxX + mathWidth, boxY + mathHeight)
                            lines[3].From, lines[3].To = Vector2.new(boxX + mathWidth, boxY + mathHeight), Vector2.new(boxX, boxY + mathHeight)
                            lines[4].From, lines[4].To = Vector2.new(boxX, boxY + mathHeight), Vector2.new(boxX, boxY)
                            for i = 1, 4 do lines[i].Color = boxColor; lines[i].Visible = true end

                            outs[1].From, outs[1].To = Vector2.new(boxX - 1, boxY - 1), Vector2.new(boxX + mathWidth + 1, boxY - 1)
                            outs[2].From, outs[2].To = Vector2.new(boxX + mathWidth + 1, boxY - 1), Vector2.new(boxX + mathWidth + 1, boxY + mathHeight + 1)
                            outs[3].From, outs[3].To = Vector2.new(boxX + mathWidth + 1, boxY + mathHeight + 1), Vector2.new(boxX - 1, boxY + mathHeight + 1)
                            outs[4].From, outs[4].To = Vector2.new(boxX - 1, boxY + mathHeight + 1), Vector2.new(boxX - 1, boxY - 1)
                            outs[5].From, outs[5].To = Vector2.new(boxX + 1, boxY + 1), Vector2.new(boxX + mathWidth - 1, boxY + 1)
                            outs[6].From, outs[6].To = Vector2.new(boxX + mathWidth - 1, boxY + 1), Vector2.new(boxX + mathWidth - 1, boxY + mathHeight - 1)
                            outs[7].From, outs[7].To = Vector2.new(boxX + mathWidth - 1, boxY + mathHeight - 1), Vector2.new(boxX + 1, boxY + mathHeight - 1)
                            outs[8].From, outs[8].To = Vector2.new(boxX + 1, boxY + 1), Vector2.new(boxX + 1, boxY + mathHeight - 1)
                            for i = 1, 8 do outs[i].Visible = true end
                        else
                            for i = 1, 4 do lines[i].Visible = false end
                            for i = 1, 8 do outs[i].Visible = false end
                        end

                        -- Healthbar
                        if Toggles.EspHealth and Toggles.EspHealth.Value then
                            local barWidth = 1.5
                            local outlinePadding = 1
                            local barX = boxX - 5
                            
                            esp.HealthOutline.Size = Vector2.new(barWidth + (outlinePadding * 2), mathHeight + (outlinePadding * 2))
                            esp.HealthOutline.Position = Vector2.new(barX - outlinePadding, boxY - outlinePadding)
                            esp.HealthOutline.Visible = true

                            local healthHeight = math.clamp(math.round(mathHeight * pct), 0, mathHeight)
                            local barY = boxY + (mathHeight - healthHeight)

                            if healthHeight > 0 then
                                esp.HealthBar.Size = Vector2.new(barWidth, healthHeight)
                                esp.HealthBar.Position = Vector2.new(barX, barY)

                                local finalCalculatedColor = hpFullColor
                                if pct > 0.5 then
                                    local alpha = math.clamp((pct - 0.5) * 2, 0, 1)
                                    finalCalculatedColor = hpHalfColor:Lerp(hpFullColor, alpha)
                                else
                                    local alpha = math.clamp(pct * 2, 0, 1)
                                    finalCalculatedColor = hpLowColor:Lerp(hpHalfColor, alpha)
                                end

                                esp.HealthBar.Color = finalCalculatedColor or Color3.fromRGB(0, 255, 0)
                                esp.HealthBar.Visible = true
                            else
                                esp.HealthBar.Visible = false
                            end

                            if Toggles.EspHealthText and Toggles.EspHealthText.Value then
                                esp.HealthText.Text = tostring(math.round(targetHp))
                                esp.HealthText.Position = Vector2.new(barX - (hpTextSize + 2), math.clamp(barY - 4, boxY - 4, boxY + mathHeight - 10))
                                esp.HealthText.Color = hpTextColor
                                esp.HealthText.Visible = true
                            else
                                esp.HealthText.Visible = false
                            end
                        else
                            esp.HealthOutline.Visible = false
                            esp.HealthBar.Visible = false
                            esp.HealthText.Visible = false
                        end

                        -- Name & Distance
                        if Toggles.EspName and Toggles.EspName.Value then
                            esp.Name.Text = selectedName
                            esp.Name.Position = Vector2.new(boxX + (mathWidth / 2), boxY - (textSize + 2))
                            esp.Name.Color = nameColor
                            esp.Name.Visible = true
                        else
                            esp.Name.Visible = false
                        end

                        if Toggles.EspDistance and Toggles.EspDistance.Value then
                            local dist = math.floor((Camera.CFrame.Position - rootPart.Position).Magnitude)
                            esp.Distance.Text = "[" .. tostring(dist) .. "m]"
                            esp.Distance.Position = Vector2.new(boxX + (mathWidth / 2), boxY + mathHeight + 2)
                            esp.Distance.Color = distColor
                            esp.Distance.Visible = true
                        else
                            esp.Distance.Visible = false
                        end
                    else
                        esp.SmoothHealth = nil
                        SetVisibilityFalse(esp)
                    end
                else
                    esp.SmoothHealth = nil
                    SetVisibilityFalse(esp)
                end
            end)
        end
    end)
end)

local EspGroup = Tabs.ESP:AddLeftGroupbox("ESP Toggle")
local EspVisualsGroup = Tabs.ESP:AddRightGroupbox("Esp Settings")

EspGroup:AddToggle("EspMaster", { Text = "Enable Drawing Esp", Default = false })

EspVisualsGroup:AddDropdown("EspFontDropdown", { Text = "ESP Font", Values = DrawingFontNames, Default = 3, Multi = false })

EspVisualsGroup:AddToggle("EspBox", { Text = "Draw Box", Default = false }):AddColorPicker("BoxColor", { Default = Color3.fromRGB(255, 255, 255) })
EspVisualsGroup:AddToggle("EspCornerBox", { Text = "Corner Box", Default = false }):AddColorPicker("CornerColor", { Default = Color3.fromRGB(255, 255, 255) })

EspVisualsGroup:AddToggle("EspName", { Text = "Draw Name", Default = false }):AddColorPicker("NameColor", { Default = Color3.fromRGB(255, 255, 255) })
EspVisualsGroup:AddDropdown("NameStyleDropdown", { Text = "Name Style", Values = {"Username", "Display Name"}, Default = 1, Multi = false })

local EspHealthToggle = EspVisualsGroup:AddToggle("EspHealth", { Text = "Draw Health Bar", Default = false })
EspHealthToggle:AddColorPicker("HPFullColor", { Default = Color3.fromRGB(0, 255, 0), Title = "Full HP Color" })
EspHealthToggle:AddColorPicker("HPHalfColor", { Default = Color3.fromRGB(255, 170, 0), Title = "Half HP Color" })
EspHealthToggle:AddColorPicker("HPLowColor", { Default = Color3.fromRGB(255, 0, 0), Title = "Low HP Color" })

EspVisualsGroup:AddSlider("HealthLerpSlider", {
    Text = "Health Lerp Speed",
    Default = 0.2,
    Min = 0.1,
    Max = 1.0,
    Rounding = 2,
    Compact = false
})

EspVisualsGroup:AddToggle("EspHealthText", { Text = "Show HP Number", Default = false }):AddColorPicker("HPTextColor", { Default = Color3.fromRGB(255, 255, 255) })
EspVisualsGroup:AddToggle("EspDistance", { Text = "Draw Distance", Default = false }):AddColorPicker("DistColor", { Default = Color3.fromRGB(255, 255, 255) })

-- [Movement Tab Components]
local MoveLeftBox = Tabs.Movement:AddLeftGroupbox("Anti Aim")
local MoveRightBox = Tabs.Movement:AddRightGroupbox("Movement & Camera")

MoveLeftBox:AddToggle("AntiAimToggle", { Text = "Enable Anti Aim", Default = false })
    :AddKeyPicker("AntiAimKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Anti Aim Bind" })

Toggles.AntiAimToggle:OnChanged(function()
    AntiAimEnabled = Toggles.AntiAimToggle.Value
end)

MoveLeftBox:AddDropdown("AntiAimModeDropdown", { Text = "Anti Aim Stance Type", Values = {"Spin", "Jitter"}, Default = 1, Multi = false })
Options.AntiAimModeDropdown:OnChanged(function()
    AntiAimMode = Options.AntiAimModeDropdown.Value
end)

MoveLeftBox:AddDropdown("JitterSettingDropdown", { Text = "Jitter Core Settings", Values = {"Multi", "5x always", "3x always", "2x always", "random"}, Default = 1, Multi = false })
Options.JitterSettingDropdown:OnChanged(function()
    JitterMode = Options.JitterSettingDropdown.Value
end)

MoveLeftBox:AddSlider("SpinSpeedSlider", { Text = "Rotation Spin Speed", Default = 15, Min = 5, Max = 50, Rounding = 0 })
Options.SpinSpeedSlider:OnChanged(function()
    AntiAimSpeed = Options.SpinSpeedSlider.Value
end)

MoveRightBox:AddToggle("ThirdPersonToggle", { Text = "Enable Third Person View", Default = false })
    :AddKeyPicker("ThirdPersonKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Third Person Bind" })

Toggles.ThirdPersonToggle:OnChanged(function()
    ThirdPersonEnabled = Toggles.ThirdPersonToggle.Value
end)

MoveRightBox:AddSlider("ThirdPersonDistanceSlider", { Text = "Third Person Distance Modifier", Default = 12, Min = 5, Max = 30, Rounding = 0 })
Options.ThirdPersonDistanceSlider:OnChanged(function()
    ThirdPersonDistance = Options.ThirdPersonDistanceSlider.Value
end)

MoveRightBox:AddToggle("BhopToggle", { Text = "Enable Auto Bunny Hop", Default = false })
    :AddKeyPicker("BhopKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Bhop Bind" })

Toggles.BhopToggle:OnChanged(function()
    BhopEnabled = Toggles.BhopToggle.Value
end)

MoveRightBox:AddSlider("BhopMultiplierSlider", { Text = "Bhop Velocity Speed Multiplier", Default = 1.5, Min = 1, Max = 5, Rounding = 1 })
Options.BhopMultiplierSlider:OnChanged(function()
    BhopSpeedMultiplier = Options.BhopMultiplierSlider.Value
end)

-- [World Tab Components]
local LightingColorsGroup = Tabs.World:AddLeftGroupbox("Lighting Colors & Time")
local WorldSkyboxBox = Tabs.World:AddLeftGroupbox("Custom Skybox System")
local WorldFogBox = Tabs.World:AddLeftGroupbox("World Fog Customization")
local WorldAtmosphereBox = Tabs.World:AddLeftGroupbox("World Atmosphere Customization")
local CameraDisplayBox = Tabs.World:AddRightGroupbox("Camera & Display Settings")

LightingColorsGroup:AddSlider("ClockTimeSlider", { Text = "Game Clock Time", Default = Lighting.ClockTime, Min = 0, Max = 24, Rounding = 1 })
Options.ClockTimeSlider:OnChanged(function()
    Lighting.ClockTime = Options.ClockTimeSlider.Value
end)

LightingColorsGroup:AddLabel("Ambient Color"):AddColorPicker("AmbientColorPicker", { Default = Lighting.Ambient })
Options.AmbientColorPicker:OnChanged(function()
    Lighting.Ambient = Options.AmbientColorPicker.Value
end)

LightingColorsGroup:AddLabel("Outdoor Ambient Color"):AddColorPicker("OutdoorAmbientColorPicker", { Default = Lighting.OutdoorAmbient })
Options.OutdoorAmbientColorPicker:OnChanged(function()
    Lighting.OutdoorAmbient = Options.OutdoorAmbientColorPicker.Value
end)

LightingColorsGroup:AddLabel("ColorShift Top Color"):AddColorPicker("ColorShiftTopColorPicker", { Default = Lighting.ColorShift_Top })
Options.ColorShiftTopColorPicker:OnChanged(function()
    Lighting.ColorShift_Top = Options.ColorShiftTopColorPicker.Value
end)

LightingColorsGroup:AddLabel("ColorShift Bottom Color"):AddColorPicker("ColorShiftBottomColorPicker", { Default = Lighting.ColorShift_Bottom })
Options.ColorShiftBottomColorPicker:OnChanged(function()
    Lighting.ColorShift_Bottom = Options.ColorShiftBottomColorPicker.Value
end)

WorldSkyboxBox:AddToggle("SkyboxToggle", { Text = "Enable Custom Skybox", Default = false })
Toggles.SkyboxToggle:OnChanged(function()
    SkyboxEnabled = Toggles.SkyboxToggle.Value
    UpdateSkybox()
end)

WorldSkyboxBox:AddDropdown("SkyboxDropdown", { Text = "Select Skybox", Values = {"Minecraft", "Minecraft 2", "Skyblox 1", "Skyblox 2", "Skyblox 3", "Skyblox 4", "Skyblox 5"}, Default = 1, Multi = false })
Options.SkyboxDropdown:OnChanged(function()
    SelectedSkybox = Options.SkyboxDropdown.Value
    UpdateSkybox()
end)

WorldFogBox:AddLabel("Fog Color"):AddColorPicker("FogColorPicker", { Default = Lighting.FogColor })
Options.FogColorPicker:OnChanged(function()
    Lighting.FogColor = Options.FogColorPicker.Value
end)

WorldFogBox:AddSlider("FogStartSlider", { Text = "Fog Start Distance", Default = Lighting.FogStart, Min = 0, Max = 5000, Rounding = 0 })
Options.FogStartSlider:OnChanged(function()
    Lighting.FogStart = Options.FogStartSlider.Value
end)

WorldFogBox:AddSlider("FogEndSlider", { Text = "Fog End Distance", Default = Lighting.FogEnd, Min = 0, Max = 10000, Rounding = 0 })
Options.FogEndSlider:OnChanged(function()
    Lighting.FogEnd = Options.FogEndSlider.Value
end)

WorldAtmosphereBox:AddToggle("AtmosphereToggle", { Text = "Enable Atmosphere", Default = false })
Toggles.AtmosphereToggle:OnChanged(function()
    AtmosphereEnabled = Toggles.AtmosphereToggle.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddLabel("Tint Color"):AddColorPicker("AtmosColorPicker", { Default = AtmosphereColor })
Options.AtmosColorPicker:OnChanged(function()
    AtmosphereColor = Options.AtmosColorPicker.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddLabel("Decay Color"):AddColorPicker("AtmosDecayPicker", { Default = AtmosphereDecay })
Options.AtmosDecayPicker:OnChanged(function()
    AtmosphereDecay = Options.AtmosDecayPicker.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddSlider("AtmosGlareSlider", { Text = "Glare Intensity", Default = AtmosphereGlare, Min = 0.1, Max = 10, Rounding = 1 })
Options.AtmosGlareSlider:OnChanged(function()
    AtmosphereGlare = Options.AtmosGlareSlider.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddSlider("AtmosHazeSlider", { Text = "Haze Density", Default = AtmosphereHaze, Min = 0.1, Max = 10, Rounding = 1 })
Options.AtmosHazeSlider:OnChanged(function()
    AtmosphereHaze = Options.AtmosHazeSlider.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddSlider("AtmosOffsetSlider", { Text = "Horizon Offset", Default = AtmosphereOffset, Min = 0.01, Max = 1, Rounding = 2 })
Options.AtmosOffsetSlider:OnChanged(function()
    AtmosphereOffset = Options.AtmosOffsetSlider.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddSlider("AtmosDensitySlider", { Text = "Atmosphere Density", Default = AtmosphereDensity, Min = 0.01, Max = 1, Rounding = 2 })
Options.AtmosDensitySlider:OnChanged(function()
    AtmosphereDensity = Options.AtmosDensitySlider.Value
    UpdateAtmosphere()
end)

CameraDisplayBox:AddSlider("CustomFovSlider", { Text = "Custom FOV", Default = 70, Min = 70, Max = 120, Rounding = 0 })
Options.CustomFovSlider:OnChanged(function()
    CustomFOVValue = Options.CustomFovSlider.Value
    Camera.FieldOfView = CustomFOVValue
end)

Camera:GetPropertyChangedSignal("FieldOfView"):Connect(function()
    if Camera.FieldOfView ~= CustomFOVValue then
        Camera.FieldOfView = CustomFOVValue
    end
end)

CameraDisplayBox:AddSlider("BlurSlider", { Text = "World Blur", Default = 0, Min = 0, Max = 5, Rounding = 1 })
Options.BlurSlider:OnChanged(function()
    local blurValue = Options.BlurSlider.Value
    local blurEffect = Lighting:FindFirstChild("hooksenseWorldBlur")
    if blurValue > 0 then
        if not blurEffect then
            blurEffect = Instance.new("BlurEffect")
            blurEffect.Name = "hooksenseWorldBlur"
            blurEffect.Parent = Lighting
        end
        blurEffect.Size = blurValue * 8
    else
        if blurEffect then blurEffect:Destroy() end
    end
end)

CameraDisplayBox:AddToggle("MotionBlurToggle", { Text = "Enable Motion Blur", Default = false })
Toggles.MotionBlurToggle:OnChanged(function()
    MotionBlurEnabled = Toggles.MotionBlurToggle.Value
end)

CameraDisplayBox:AddSlider("MotionBlurIntensitySlider", { Text = "Motion Blur Intensity", Default = 1.5, Min = 0.5, Max = 5.0, Rounding = 1 })
Options.MotionBlurIntensitySlider:OnChanged(function()
    MotionBlurIntensity = Options.MotionBlurIntensitySlider.Value
end)

CameraDisplayBox:AddSlider("FpsCapSlider", { Text = "FPS Cap Limit", Default = 60, Min = 60, Max = 999, Rounding = 0 })
Options.FpsCapSlider:OnChanged(function()
    if setfpscap then setfpscap(Options.FpsCapSlider.Value) end
end)

-- [Addons Tab Components]
local BlacklistPlayersGroup = Tabs.Addons:AddLeftGroupbox("Loaders Scripts")
local TargetHudConfigGroup = Tabs.Addons:AddRightGroupbox("Target HUD Settings")

TargetHudConfigGroup:AddToggle("TargetHudMasterToggle", { Text = "Enable Target HUD", Default = false })
Toggles.TargetHudMasterToggle:OnChanged(function()
    TargetHudToggle = Toggles.TargetHudMasterToggle.Value
end)

TargetHudConfigGroup:AddSlider("TargetHudPosXSlider", { Text = "Position X Offset", Default = 0, Min = -1000, Max = 1000, Rounding = 0 })
Options.TargetHudPosXSlider:OnChanged(function()
    TargetHudPosX = Options.TargetHudPosXSlider.Value
end)

TargetHudConfigGroup:AddSlider("TargetHudPosYSlider", { Text = "Position Y Offset", Default = 0, Min = -1000, Max = 1000, Rounding = 0 })
Options.TargetHudPosYSlider:OnChanged(function()
    TargetHudPosY = Options.TargetHudPosYSlider.Value
end)

TargetHudConfigGroup:AddLabel("Border Color 1"):AddColorPicker("HudBorderColor1Picker", { Default = Color3.fromRGB(0, 255, 100) })
Options.HudBorderColor1Picker:OnChanged(function()
    TargetHudBorderColor1 = Options.HudBorderColor1Picker.Value
    BorderGradient.Color = ColorSequence.new({
        ColorSequenceKeypoint.new(0, TargetHudBorderColor1),
        ColorSequenceKeypoint.new(1, TargetHudBorderColor2)
    })
end)

TargetHudConfigGroup:AddLabel("Border Color 2"):AddColorPicker("HudBorderColor2Picker", { Default = Color3.fromRGB(0, 150, 0) })
Options.HudBorderColor2Picker:OnChanged(function()
    TargetHudBorderColor2 = Options.HudBorderColor2Picker.Value
    BorderGradient.Color = ColorSequence.new({
        ColorSequenceKeypoint.new(0, TargetHudBorderColor1),
        ColorSequenceKeypoint.new(1, TargetHudBorderColor2)
    })
end)

TargetHudConfigGroup:AddLabel("Health Color: High (>60%)"):AddColorPicker("HudHealthHighPicker", { Default = Color3.fromRGB(0, 255, 100) })
Options.HudHealthHighPicker:OnChanged(function()
    TargetHudHealthHigh = Options.HudHealthHighPicker.Value
end)

TargetHudConfigGroup:AddLabel("Health Color: Medium (30%-60%)"):AddColorPicker("HudHealthMidPicker", { Default = Color3.fromRGB(255, 200, 0) })
Options.HudHealthMidPicker:OnChanged(function() 
    TargetHudHealthMid = Options.HudHealthMidPicker.Value
end)

TargetHudConfigGroup:AddLabel("Health Color: Low (<30%)"):AddColorPicker("HudHealthLowPicker", { Default = Color3.fromRGB(255, 50, 50) })
Options.HudHealthLowPicker:OnChanged(function()
    TargetHudHealthLow = Options.HudHealthLowPicker.Value
end)

BlacklistPlayersGroup:AddButton({ Text = "walkspeed", Func = function()
    local success, err = pcall(function()
        loadstring(game:HttpGet('https://raw.githubusercontent.com/19mdSkibidi/19sMooze-Mobile-Rework/refs/heads/main/Mooze%20Mob'))()
    end)
    if success then
        Library:Notify("successfully!")
    else
        Library:Notify("Error loading script: " .. tostring(err))
    end
end })

local InterfaceGroup = Tabs.UI:AddLeftGroupbox("Menu Customization")
local MenuGroup = Tabs.UI:AddLeftGroupbox("Menu Settings")

InterfaceGroup:AddDropdown("UIFontDropdown", { Text = "UI Custom Font", Values = RobloxFontsList, Default = table.find(RobloxFontsList, "Cartoon") or 1, Multi = false })

Options.UIFontDropdown:OnChanged(function()
    pcall(function()
        local targetFont = Enum.Font[Options.UIFontDropdown.Value]
        if not targetFont then return end
        local parentGui = Library.ScreenGui or Library.Main
        if parentGui then
            for _, desc in ipairs(parentGui:GetDescendants()) do
                if desc:IsA("TextLabel") or desc:IsA("TextButton") or desc:IsA("TextBox") then 
                    desc.Font = targetFont 
                end
            end
        end
    end)
end)

MenuGroup:AddToggle("KeybindMenuOpen", { Default = false, Text = "Open Keybind Menu", Callback = function(value) Library.KeybindFrame.Visible = value end})
MenuGroup:AddToggle("ShowCustomCursor", {Text = "Custom Cursor", Default = true, Callback = function(Value) Library.ShowCustomCursor = Value end})
MenuGroup:AddDivider()
MenuGroup:AddLabel("Menu bind"):AddKeyPicker("MenuKeybind", { Default = "RightShift", NoUI = true, Text = "Menu keybind" })
MenuGroup:AddButton("Unload", function() Library:Unload() end)

Library.ToggleKeybind = Options.MenuKeybind

Library:OnUnload(function()
    for player, _ in pairs(ESP_Drawing_Storage) do
        RemoveDrawingESP(player)
    end
    table.clear(ESP_Drawing_Storage)
    
    Library.Unloaded = true
end)

ThemeManager:SetLibrary(Library)
SaveManager:SetLibrary(Library)
SaveManager:IgnoreThemeSettings()
SaveManager:SetIgnoreIndexes({ "MenuKeybind", "UIFontDropdown", "EspFontDropdown" })
ThemeManager:SetFolder("SilentHubV3")
SaveManager:SetFolder("SilentHubV3/configs")
SaveManager:BuildConfigSection(Tabs.UI)
ThemeManager:ApplyToTab(Tabs.UI)
SaveManager:LoadAutoloadConfig()
